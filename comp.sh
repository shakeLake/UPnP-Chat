#!/bin/bash

echo -e "MINIUPNPC"
cd "third-party/miniupnpc-2.2.4"
cmake -G "MinGW Makefiles" -B "../../build/miniupnpc-build"

cd "../../build/miniupnpc-build"
mingw32-make

echo -e "\nUPNP"
cd "../../upnp"
cmake -G "MinGW Makefiles" -B "../build/upnp-build"

cd "../build/upnp-build"
mingw32-make

echo -e "\nCHAT"
cd "../../chat"
cmake -G "MinGW Makefiles" -B "../build/chat-build"

cd "../build/chat-build"
mingw32-make