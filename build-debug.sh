#!/bin/bash

# set DEBUG in config.hpp

echo -e "Build"
cmake -G "MinGW Makefiles" -B "build" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_BUILD_TYPE=RelWithDebInfo

cd build
mingw32-make