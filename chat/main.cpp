// chat
#include "include/default.hpp"

int main()
{
    ucd::Data user;

    ucu::Ui intrface;
    user.SetIpAddr(intrface.AskIpAddress());

    return 0;
}