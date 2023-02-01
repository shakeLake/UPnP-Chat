cmake_minimum_required(VERSION 3.2)

project(Tests)

option (BUILD_CLIENT_TEST "client" TRUE)
option (BUILD_SERVER_TEST "server" TRUE)
option (BUILD_UPNP_TEST "upnp" TRUE)

add_subdirectory("../upnp" "upnp-build")

find_package(Threads REQUIRED)

add_library(asio INTERFACE)
target_include_directories(asio SYSTEM INTERFACE "${CMAKE_SOURCE_DIR}/third-party/asio-1.24.0/include")
target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)
target_link_libraries(asio INTERFACE Threads::Threads)

if (BUILD_CLIENT_TEST)
    add_executable(cli client.cpp)
    target_link_libraries(cli upnp-static asio)
endif()

if (BUILD_SERVER_TEST)
    add_executable(srv server.cpp)
    target_link_libraries(srv upnp-static asio)
endif()

if (BUILD_UPNP_TEST)
    add_executable(upnp upnp.cpp)
    target_link_libraries(upnp upnp-static)
endif()