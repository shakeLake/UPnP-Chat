// chat
#include "include/default.hpp"

int main()
{
    /* port mapping */
    //shakeLake::Upnp client("50001", "50001");
    //client.PortForwarding();

    ucd::Data test("Name", "192.168.0.1");
    test.SetMessage();

    asio::streambuf::const_buffers_type t_message = test.Construction();

    return 0;
}