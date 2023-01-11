#ifndef UPNP_HPP_
#define UPNP_HPP_

// DEBUG or RELEASE
#define DEBUG

#include <iostream>

/* MINIUPNPc */
#include "../third-party/miniupnpc-2.2.4/include/miniupnpc.h"
#include "../third-party/miniupnpc-2.2.4/include/miniwget.h"
#include "../third-party/miniupnpc-2.2.4/include/portlistingparse.h"
#include "../third-party/miniupnpc-2.2.4/include/upnpcommands.h"
#include "../third-party/miniupnpc-2.2.4/include/upnperrors.h"
#include "../build/miniupnpc-build/miniupnpcstrings.h"

namespace shakeLake
{
    class Upnp
    {
        private:
            const char* external_port;
            const char* internal_port;

            struct UPNPUrls urls;
		    struct IGDdatas data;

            int error;

            // upnpDiscover
            struct UPNPDev * devlist;

            // UPNP_GetValidIGD 
            char LAN_addr[64];

            // UPNP_GetExternalIPAddress
            char externalIPAddress[40];

            // UPNP_GetSpecificPortMappingEntry
            char intClient[40];
            char intPort[6];
            char duration[16];
        private:
            // deletes redirected port
            void DeletePortForwarding();
        public:
            // internal port and external port
            Upnp(const char*, const char*);
            ~Upnp();

            // redirects port
            void PortForwarding();
    };
}

#endif /* UPNP_HPP_ */