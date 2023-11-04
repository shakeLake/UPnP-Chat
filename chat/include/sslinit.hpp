#ifndef SSLCLIENTINIT_HPP_
#define SSLCLIENTINIT_HPP_

#include "../../third-party/asio-1.24.0/include/asio.hpp"
#include "../../third-party/asio-1.24.0/include/asio/ssl.hpp"

// data
#include "data.hpp"

class SSLContext
{
private:
    const bool CLIENT = true;
    const bool SERVER = false;

private: 
    std::string GetPassword();

public:
    SSLContext() = default;
    ~SSLContext() = default;

    asio::ssl::context operator()(bool);

    bool VerifyCertificate(bool, asio::ssl::verify_context&);

};

#endif /* SSLCLIENTINIT_HPP_ */