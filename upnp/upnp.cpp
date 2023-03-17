#include "upnp.hpp"

SL_upnp::Upnp::Upnp(std::string& ext_p, std::string& int_p)
{
    #ifdef _WIN32
        nResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

        if(nResult != NO_ERROR)
        {
            std::cerr << "WSAStartup() failed." << std::endl;
			return;
        }
    #endif /* _WIN32 */

    // discover UPnP devices on the network.
    localport = UPNP_LOCAL_PORT_ANY;
    devlist = upnpDiscover(2000, NULL, NULL, localport, 0, 2, &error);

   	if (error == UPNPDISCOVER_SUCCESS)
	{
    	std::cout << "upnpDiscover -> done" << std::endl;
	}
    else
	{ 
    	std::cerr << "Error: UPNPDISCOVER_UNKNOWN_ERROR" << std::endl;
		return;
	}

    external_port = ext_p.data();
    internal_port = int_p.data();

    error = UPNP_GetValidIGD(devlist, &urls, &data, LAN_addr, sizeof(LAN_addr));

	switch(error) 
	{
		case 1:
			std::cout << "Found valid IGD : " << urls.controlURL << std::endl;
			break;
		case 2:
			std::cout << "Found a (not connected?) IGD : " << urls.controlURL << std::endl;
			return;
		case 3:
			std::cout << "UPnP device found. Is it an IGD ? : " << urls.controlURL << std::endl;
			break;
		default:
			std::cout << "Found device (igd ?) : " << urls.controlURL << std::endl;
			return;
	}
}

SL_upnp::Upnp::~Upnp()
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

bool SL_upnp::Upnp::PortForwarding()
{
    error = UPNP_GetExternalIPAddress(urls.controlURL, data.first.servicetype, externalIPAddress);

    if (error == UPNPCOMMAND_SUCCESS)
	{
    	std::cout << "External IP: " << externalIPAddress << std::endl;
	}
    else
	{
     	std::cout << "Error: UPNP_GetExternalIPAddress" << std::endl;
		return false;
	}

    error = UPNP_AddPortMapping(urls.controlURL, data.first.servicetype, external_port, internal_port, LAN_addr, nullptr, "tcp", nullptr, nullptr);

    if(error != UPNPCOMMAND_SUCCESS)
    {
		std::cerr << "AddPortMapping(" << external_port << ", " << internal_port << ", " << LAN_addr << ") ";
        std::cerr << "failed with code " << external_port << " (" << strupnperror(error) << ')' << std::endl;

		return false;
    }

    error = UPNP_GetSpecificPortMappingEntry(urls.controlURL, data.first.servicetype, external_port, "tcp", nullptr, intClient, intPort, nullptr, nullptr, duration);

    if(error != UPNPCOMMAND_SUCCESS) 
	{
    	std::cerr << "GetSpecificPortMappingEntry() failed with code " << error << " (" << strupnperror(error) << ')' << std::endl;
	
		return false;
	}	
    else 
    {
    	std::cout << "InternalIP:Port = " << intClient << ':' << intPort << std::endl;

        std::cout << "external " << externalIPAddress << ':' << external_port << ' ' << "tcp";
        std::cout << " is redirected to internal " << intClient << ':' << intPort << " (duration = " << duration << ')' << std::endl;
    }

	return true;
}

void SL_upnp::Upnp::DeletePortForwarding()
{
    error = UPNP_DeletePortMapping(urls.controlURL, data.first.servicetype, external_port, "tcp", nullptr);

    if (error != UPNPCOMMAND_SUCCESS)
    	std::cerr << "UPNP_DeletePortMapping() failed with code : " << error << std::endl;
    else
    	std::cout << "UPNP_DeletePortMapping() returned : " << error << std::endl;
}
