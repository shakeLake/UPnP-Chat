#!/bin/bash

echo -e "Build"
cmake -G "MinGW Makefiles" -B "build" -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="C:/Program Files/Qt/lib/cmake"

cd build
mingw32-make