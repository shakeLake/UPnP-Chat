cmake_minimum_required(VERSION 3.2...3.5)

project(Updater)

find_package(Threads REQUIRED)

add_library(asio INTERFACE)

target_include_directories(asio INTERFACE "${CMAKE_SOURCE_DIR}/third-party/asio-1.24.0/include")
target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)
target_link_libraries(asio INTERFACE Threads::Threads)

add_library(uptd STATIC update.cpp update.hpp)

add_executable(Updater up.cpp)

if (WIN32)
	target_link_libraries(uptd PUBLIC asio ws2_32)
endif()

if (UNIX)
	target_link_libraries(uptd PUBLIC asio)
endif()

target_link_libraries(Updater PRIVATE uptd)