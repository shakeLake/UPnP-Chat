// chat
#include "include/default.hpp"

int main()
{
    /* port mapping */
    SL_upnp::Upnp client("50001", "50001");
    client.PortForwarding();

    /* data test */
    //ucd::Data test("Name", "192.168.0.1");
    
    //std::string* name = new std::string("Name1");
    //ucu::Ui testUI(name, name);

    //test.SetMessage(testUI.EnterMessage());

    return 0;
}