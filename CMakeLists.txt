cmake_minimum_required(VERSION 3.2)

project(upnp_chat)

option (BUILD_TESTS "tests" FALSE)

if (BUILD_TESTS)
    add_subdirectory("test" "tests-build")
endif()

add_subdirectory("chat" "chat-build")