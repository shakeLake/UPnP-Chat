#!/bin/bash

# set RELEASE in config.hpp

echo -e "Build"
cmake -G "MinGW Makefiles" -B "build-release" -DCMAKE_BUILD_TYPE=Release

cd build-release
mingw32-make

echo -e "\nExecute"
cd chat-build
./chatStart.exe