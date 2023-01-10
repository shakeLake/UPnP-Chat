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
            int error;

            // upnpDiscover
            struct UPNPDev * devlist;

        private:
            // deletes redirected port
            // - external port
            void DeletePortForwarding(const char*);
        public:
            Upnp();
            ~Upnp();

            // redirects port
            void PortForwarding
            (
                const char*, // internal_port
                const char*, // external_port
            );
    };
}

#endif /* UPNP_HPP_ */