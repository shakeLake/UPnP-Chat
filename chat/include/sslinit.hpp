#ifndef SSLCLIENTINIT_HPP_
#define SSLCLIENTINIT_HPP_

#include "../../third-party/asio-1.24.0/include/asio.hpp"
#include "../../third-party/asio-1.24.0/include/asio/ssl.hpp"

class SSLContext
{
private:
    const bool CLIENT = true;
    const bool SERVER = false;

public:
    SSLContext() = default;
    ~SSLContext() = default;
    
    bool VerifyCertificate(bool preverified, asio::ssl::verify_context& contxt)
    {
        char subject_name[256];
        X509* cert = X509_STORE_CTX_get_current_cert(contxt.native_handle());
        X509_NAME_oneline(X509_get_subject_name(cert), subject_name, 256);

        return preverified;
    }

    asio::ssl::context operator()(bool client_or_server)
    {
        asio::ssl::context ctx(asio::ssl::context::sslv23);
        
        if (client_or_server == CLIENT)
            ctx.load_verify_file("ca.pem");
        else if (client_or_server == SERVER)
        {
            // ctx server
        }

        return ctx;
    };

};

#endif /* SSLCLIENTINIT_HPP_ */