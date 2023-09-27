cmake_minimum_required(VERSION 3.2...3.5)

project(upnp_chat VERSION 0.5.0 LANGUAGES CXX)

set(IS_TESTING "TESTINGOFF" CACHE STRING "TESTING IS OFF (ON)")
message(STATUS "${MY_CACHE_VAR}")

set(CMAKE_CXX_STANDARD 20)

set(ZLIB_USE_STATIC_LIBS "ON")
set(CMAKE_EXE_LINKER_FLAGS "-static")

if (IS_TESTING EQUAL "TESTINGOFF")
    add_subdirectory("tests" "test-build")
endif()

add_subdirectory("app" "app-build")