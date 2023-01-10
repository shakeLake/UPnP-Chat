cmake_minimum_required(VERSION 3.2)

project(upnp)

add_library(upnp upnp.cpp upnp.hpp)

get_filename_component(ROOT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
target_link_libraries(upnp "${ROOT_DIR}/build/miniupnpc-build/libminiupnpc.a")
