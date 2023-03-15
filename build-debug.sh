#!/bin/bash

# set DEBUG in config.hpp

echo -e "Build"
cmake -G "MinGW Makefiles" -B "build-debug" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_BUILD_TYPE=RelWithDebInfo

cd build-debug
mingw32-make