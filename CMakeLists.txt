cmake_minimum_required(VERSION 3.2...3.5)

project(upnp_chat VERSION 0.5.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(ZLIB_USE_STATIC_LIBS "ON")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_subdirectory("app" "app-build")