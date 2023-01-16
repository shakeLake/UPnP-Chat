#!/bin/bash

echo -e "Build"
cmake -G "MinGW Makefiles" -B "build"

cd build
mingw32-make

echo -e "\nExecute"
cd chat-build
./chatStart.exe