cmake_minimum_required(VERSION 3.2)

project(chat)

message("CMAKE_MODULE_PATH is ${CMAKE_MODULE_PATH}")

find_package(Threads REQUIRED)

add_library(asio INTERFACE)

get_filename_component(ROOT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
target_include_directories(asio SYSTEM INTERFACE "${ROOT_DIR}/third-party/asio-1.24.0/include")

target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)

target_link_libraries(asio INTERFACE Threads::Threads)

add_executable(chatStart main.cpp)

target_link_libraries(chatStart asio "${ROOT_DIR}/build/upnp-build/libupnp.a" ws2_32)