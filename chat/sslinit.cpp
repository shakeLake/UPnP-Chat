#include "include/sslinit.hpp"

std::string SSLContext::GetPassword()
{
    return "test";
}

asio::ssl::context SSLContext::operator()(bool client_or_server)
{
    ucd::Data logs;
    logs.Log("ctx");

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
        ctx.use_private_key_file("serverKey.pem", asio::ssl::context::pem);
        ctx.use_tmp_dh_file("dh4096.pem");
    }

    return ctx;
};

bool SSLContext::VerifyCertificate(bool preverified, asio::ssl::verify_context& contxt)
{
    char subject_name[256];
    X509* cert = X509_STORE_CTX_get_current_cert(contxt.native_handle());
    X509_NAME_oneline(X509_get_subject_name(cert), subject_name, 256);
    
    ucd::Data logs;
    logs.Log(subject_name);
    std::cerr << "Verifying " << subject_name << "\n";

    return preverified;
}