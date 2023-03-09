#!/bin/bash

cmake -G "MinGW Makefiles" -B "build"

cd build
mingw32-make
