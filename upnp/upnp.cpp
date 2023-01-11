#include "upnp.h"

shakeLake::Upnp::Upnp(const char* extport, const char* intport)
{
    #ifdef _WIN32
        WSADATA wsaData;
        int nResult = WSAStartup(MAKEWORD(2,2), &wsaData);
        if(nResult != NO_ERROR)
        {
            std::cerr << "WSAStartup() failed." << std::endl;
            return -1;
        }
    #endif /* _WIN32 */

    external_port = extport;
    internal_port = intport;

    // discover UPnP devices on the network.
    devlist = upnpDiscover(2000, NULL, NULL, 1, 0, 2, &error)
    #ifdef DEBUG
        if (error == UPNPDISCOVER_SUCCESS)
            std::cout << "upnpDiscover -> done" << std::endl;
        else 
            std::cerr << "Error: UPNPDISCOVER_UNKNOWN_ERROR" << std::endl;
    #endif

    error = UPNP_GetValidIGD(devlist, &urls, &data, LAN_addr, sizeof(LAN_addr))
    #ifdef DEBUG
		switch(error_code) {
		case 1:
			std::cout << "Found valid IGD : " << urls.controlURL << std::endl;
			break;
		case 2:
			std::cout << "Found a (not connected?) IGD : " << urls.controlURL << std::endl;
			break;
		case 3:
			std::cout << "UPnP device found. Is it an IGD ? : " << urls.controlURL << std::endl;
			break;
		default:
			std::cout << "Found device (igd ?) : " << urls.controlURL << std::endl;
		}
    #endif
}

shakeLake::Upnp::~Upnp()
{   
    freeUPNPDevlist(devlist);

    DeletePortForwarding();

    #ifdef _WIN32
        nResult = WSACleanup();
        if(nResult != NO_ERROR) 
        {
            std::cerr << "WSACleanup() failed." << std::endl;
        }
    #endif /* _WIN32 */
}

void shakeLake::Upnp::PortForwarding(const char* internal_port, const char* external_port)
{
    error = UPNP_GetExternalIPAddress(urls->controlURL, data->first.servicetype, externalIPAddress);
    #ifdef DEBUG
        if (error == UPNPCOMMAND_SUCCESS)
            std::cout << "External IP: " << externalIPAddress << std::endl;
        else
            std::cout << "Error: UPNP_GetExternalIPAddress" << std::endl;
    #endif

    error = UPNP_AddPortMapping(urls->controlURL, data->first.servicetype, external_port, internal_port, LAN_addr, nullptr, "tcp", nullptr, nullptr);
    #ifdef DEBUG
        if(r != UPNPCOMMAND_SUCCESS)
        {
			std::cerr << "AddPortMapping(" << eport << ", " << iport << ", " << iaddr << ") ";
            std::cerr << "failed with code " << error << " (" << strupnperror(error) << ')' << std::endl;
        }
    #endif 

    error = UPNP_GetSpecificPortMappingEntry(urls->controlURL, data->first.servicetype, external_port, "tcp", nullptr, intClient, intPort, nullptr, nullptr, duration);
    #ifdef DEBUG
        if(error != UPNPCOMMAND_SUCCESS) 
            std::cerr << "GetSpecificPortMappingEntry() failed with code " << error << " (" << strupnperror(error) << '0' << std::endl;
        else 
        {
            std::cout << "InternalIP:Port = " << intClient << ':' << intPort << std::endl;

            std::cout << "external " << externalIPAddress << ':' << external_port << ' ' << "tcp";
            std::cout << " is redirected to internal " << intClient << ':' << intPort << " (duration = " << duration << ')' << std::endl;
        }
    #endif
}

void shakeLake::Upnp::DeletePortForwarding()
{
    error = UPNP_DeletePortMapping(urls->controlURL, data->first.servicetype, external_port, "tcp", nullptr);
    #ifdef DEBUG
        if (error != UPNPCOMMAND_SUCCESS)
            std::cerr << "UPNP_DeletePortMapping() failed with code : " << error << std::endl;
        else
            std::cout << "UPNP_DeletePortMapping() returned : " << error << std::endl
    #endif
}