#ifndef SSLCLIENTINIT_HPP_
#define SSLCLIENTINIT_HPP_

#include "../../third-party/asio-1.24.0/include/asio/ssl.hpp"

class SSLContext
{
public:
    SSLContext() = default;
    ~SSLContext() = default;

    asio::ssl::context operator(asio::ssl::stream<asio::ip::tcp::socket>& sckt)()
    {
        asio::ssl::context ctx(asio::ssl::context::sslv23);
        ctx.load_verify_file("ca.pem");

		sckt.set_verify_mode(asio::ssl::verify_peer);
		sckt.set_verify_callback();

        return ctx;
    };

};

#endif /* SSLCLIENTINIT_HPP_ */