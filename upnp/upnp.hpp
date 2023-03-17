#ifndef UPNP_HPP_
#define UPNP_HPP_

// DEBUG or RELEASE
#include "../config.hpp"

// I / O
#include <iostream>

// WSAStartup and WSACleanup
#ifdef _WIN32
    #include <winsock2.h>
    #include "../third-party/miniupnpc-2.2.4/src/win32_snprintf.h"
#endif

// MINIUPNPc
#include "../third-party/miniupnpc-2.2.4/include/miniupnpc.h"
#include "../third-party/miniupnpc-2.2.4/include/miniwget.h"
#include "../third-party/miniupnpc-2.2.4/include/portlistingparse.h"
#include "../third-party/miniupnpc-2.2.4/include/upnpcommands.h"
#include "../third-party/miniupnpc-2.2.4/include/upnperrors.h"

#include "../build/app-build/chat-build/upnp-build/miniupnpc-build/miniupnpcstrings.h"

namespace SL_upnp
{
    class Upnp
    {
        private:
            struct UPNPUrls urls;
		    struct IGDdatas data;

            int error;

            // upnpDiscover
            struct UPNPDev* devlist;
            int localport;
            
            // UPNP_GetValidIGD 
            char LAN_addr[64] = "unset";

            // UPNP_GetExternalIPAddress
            char externalIPAddress[40];

            // UPNP_GetSpecificPortMappingEntry
            char intClient[40];
            char intPort[6];
            char duration[16];

            // _WIN32
            WSADATA wsaData;
            int nResult;

            // ports
            char* external_port;
            char* internal_port;
        private:
            // deletes redirected port
            void DeletePortForwarding();
        public:
            // internal port and external port
            Upnp(std::string&, std::string&);
            ~Upnp();

            // redirects port
            bool PortForwarding();
    };
}

#endif /* UPNP_HPP_ */
