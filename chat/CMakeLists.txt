cmake_minimum_required(VERSION 3.2)

project(chat)

add_subdirectory("../upnp" "upnp-build")

find_package(Threads REQUIRED)

add_library(asio INTERFACE)

target_include_directories(asio SYSTEM INTERFACE "${CMAKE_SOURCE_DIR}/third-party/asio-1.24.0/include")

target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)

target_link_libraries(asio INTERFACE Threads::Threads)

add_executable(chatStart main.cpp)

target_link_libraries(chatStart asio upnp-static)