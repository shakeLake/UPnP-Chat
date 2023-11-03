#ifndef SSLCLIENTINIT_HPP_
#define SSLCLIENTINIT_HPP_

#include "../../third-party/asio-1.24.0/include/asio.hpp"
#include "../../third-party/asio-1.24.0/include/asio/ssl.hpp"
#include <cstdlib> 
#include <ctime>

class SSLContext
{
private:
    const bool CLIENT = true;
    const bool SERVER = false;

private: 
    std::string GetPassword()
    {
        std::srand(std::time(0));
        return std::to_string(rand());
    }

public:
    SSLContext() = default;
    ~SSLContext() = default;

    asio::ssl::context operator()(bool client_or_server)
    {
        asio::ssl::context ctx(asio::ssl::context::sslv23);
        
        if (client_or_server == CLIENT)
            ctx.load_verify_file("ca.pem");
        else if (client_or_server == SERVER)
        {
            ctx.set_options(asio::ssl::context::default_workarounds 
                            | asio::ssl::context::no_sslv2
                            | asio::ssl::context::single_dh_use);

            ctx.set_password_callback(std::bind(&SSLContext::GetPassword, this));
            ctx.use_certificate_chain_file("server.pem");
            ctx.use_private_key_file("server.pem", asio::ssl::context::pem);
            ctx.use_tmp_dh_file("dh4096.pem");
        }

        return ctx;
    };

    bool VerifyCertificate(bool preverified, asio::ssl::verify_context& contxt)
    {
        char subject_name[256];
        X509* cert = X509_STORE_CTX_get_current_cert(contxt.native_handle());
        X509_NAME_oneline(X509_get_subject_name(cert), subject_name, 256);

        return preverified;
    }


};

#endif /* SSLCLIENTINIT_HPP_ */