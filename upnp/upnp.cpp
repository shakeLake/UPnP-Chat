#include "upnp.h"

shakeLake::Upnp::Upnp()
{
    // wasapstartup

    // discover UPnP devices on the network.
    devlist = upnpDiscover(2000, NULL, NULL, 1, 0, 2, &error)
    #ifdef DEBUF
    #endif

    // upnp_GetIGDFromUrl

    // upnp_GetValidIGD

    // miniwget
}

shakeLake::Upnp::~Upnp()
{
    // wasapcleanup
    
    // DeletePortForwarding

    // freeUPNPDevlist
}

void shakeLake::Upnp::PortForwarding(const char* internal_port, const char* external_port)
{
    // _GetExternalIPAddress()

    // UPNP_AddPortMapping

    // _getSpecificPortMappingEntry
}

void shakeLake::Upnp::DeletePortForwarding(const char* external_port)
{
    // *_DeletePortMapping
}