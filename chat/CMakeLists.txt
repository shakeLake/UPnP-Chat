cmake_minimum_required(VERSION 3.2)

project(chat)

# UNION
option(CHAT_CLIENT_TEST "Build Chat-Client Test" TRUE)
option(CHAT_SERVER_TEST "Build Chat-Server Test" FALSE)
option(CHAT "Default" FALSE)

# add_subdirectory("../upnp" "upnp-build")

find_package(Threads REQUIRED)

add_library(asio INTERFACE)

target_include_directories(asio INTERFACE "${CMAKE_SOURCE_DIR}/third-party/asio-1.24.0/include")
target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)
target_link_libraries(asio INTERFACE Threads::Threads)

if (CHAT_CLIENT_TEST)
	set(CHAT_SOURCE 
		data.cpp
		"include/data.hpp"
		client.cpp
		"include/client.hpp"
	)
	add_library(test-client-lib STATIC ${CHAT_SOURCE})

	target_link_libraries(test-client-lib asio)
	
	add_executable(client_test testchatclient.cpp)	

	target_link_libraries(client_test test-client-lib)
endif()
