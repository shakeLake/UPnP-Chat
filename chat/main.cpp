// chat
#include "include/default.hpp"

int main()
{
    ucd::Data user;

    ucu::Ui intrface;
    user.SetIpAddr(intrface.AskIpAddress());

    asio::io_context io_c;
    ucc::Client one(io_c, user.ipaddr, ext_port);
    
    one.Connect();

    return 0;
}