#include "update.hpp"

UUpdater::Update::Update(std::string& ip, std::string* port) : sckt(io_c), rslvr(io_c)
{
    endpnt = rslvr.resolve(ip, port, er_code); 

    if (endpnt)
        std::cerr << "Error: Endpoint" << std::endl;

    Connect(); 
}