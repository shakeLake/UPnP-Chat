cmake_minimum_required(VERSION 3.2)

project(chat)

add_subdirectory("../upnp" "upnp-build")

find_package(Threads REQUIRED)

add_library(asio INTERFACE)
target_include_directories(asio SYSTEM INTERFACE "${CMAKE_SOURCE_DIR}/third-party/asio-1.24.0/include")
target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)
target_link_libraries(asio INTERFACE Threads::Threads)

# client.cpp server.cpp ui.cpp
set(CHAT_SOURCE data.cpp)
add_library(upnp_chat-static STATIC ${CHAT_SOURCE})
target_link_libraries(upnp_chat-static asio)

add_executable(chatStart main.cpp)

target_link_libraries(chatStart upnp-static upnp_chat-static)