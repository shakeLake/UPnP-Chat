#!/bin/bash

# set RELEASE in config.hpp

echo -e "Build"
cmake -G "MinGW Makefiles" -B "build" -DCMAKE_BUILD_TYPE=Release

cd build
mingw32-make