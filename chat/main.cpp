#include <iostream>

//#include "../third-party/asio-1.24.0/include/asio.hpp"

#include "../upnp/upnp.hpp"

int main()
{
    shakeLake::Upnp client("50001", "50001");

    client.PortForwarding();

    std::cin.get();

    return 0;
}