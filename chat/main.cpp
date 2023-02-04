// chat
#include "include/default.hpp"

int main()
{
    ucd::Data user;

    ucu::Ui intrface;
    user.SetIpAddr(intrface.AskIpAddress());

    /*
    asio::io_context client_io_c;
    ucc::Client one(client_io_c, user.ipaddr, ext_port);
    one.Connect();

    user.SetMessage(intrface.EnterMessage());

    one.SendTo(user.Construction());
    */

    asio::io_context server_io_c;
    ucs::Server two(server_io_c, ext_port);
    two.Listening();

    two.ReadFrom();

    return 0;
}