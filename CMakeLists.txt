cmake_minimum_required(VERSION 3.2)

project(upnp_chat)

set(ZLIB_USE_STATIC_LIBS "ON")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_subdirectory("app" "app-build")