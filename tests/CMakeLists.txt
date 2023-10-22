cmake_minimum_required(VERSION 3.2...3.5)

project(nettesting)

add_subdirectory("../chat" "chat-build")

file(COPY "testcases/" DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/ )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(srv servertest.cpp)
target_link_libraries(srv PRIVATE GTest::gtest_main)
target_link_libraries(srv PRIVATE upnp_chat-static)

add_executable(cli clienttest.cpp)
target_link_libraries(cli PRIVATE GTest::gtest_main)
target_link_libraries(cli PRIVATE upnp_chat-static)

add_executable(fh filehandlertest.cpp)
target_link_libraries(fh PRIVATE GTest::gtest_main)
target_link_libraries(fh PRIVATE upnp_chat-static)

include(GoogleTest)
gtest_discover_tests(srv)
gtest_discover_tests(cli)
gtest_discover_tests(fh)