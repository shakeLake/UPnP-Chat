cmake_minimum_required(VERSION 3.2)

project(upnp)

add_subdirectory("../third-party/miniupnpc-2.2.4" miniupnpc-build)

add_library(upnp-static upnp.cpp upnp.hpp)

target_link_libraries(upnp-static libminiupnpc-static)