cmake_minimum_required(VERSION 3.2)

project(chat)

# UNION
option(CHAT_CLIENT_TEST "Build Chat-Client Test" TRUE)
option(CHAT_SERVER_TEST "Build Chat-Server Test" TRUE)
option(CHAT "Default" FALSE)

# add_subdirectory("../upnp" "upnp-build")

find_package(Threads REQUIRED)

add_library(asio INTERFACE)

target_include_directories(asio INTERFACE "${CMAKE_SOURCE_DIR}/third-party/asio-1.24.0/include")
target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)
target_link_libraries(asio INTERFACE Threads::Threads)

if (CHAT_CLIENT_TEST)
	set(CHAT_CLIENT_SOURCE 
		data.cpp
		"include/data.hpp"
		client.cpp
		"include/client.hpp"
		"include/default.hpp"
	)

	add_library(chat_client-test STATIC ${CHAT_CLIENT_SOURCE})
	target_link_libraries(chat_client-test PUBLIC asio)	

	add_executable(client_test testchatclient.cpp)
	target_link_libraries(client_test PRIVATE chat_client-test ws2_32)
endif()

if (CHAT_SERVER_TEST)
	set(CHAT_SERVER_SOURCE 
		data.cpp
		"include/data.hpp"
		server.cpp
		"include/server.hpp"
		"include/default.hpp"
	)

	add_library(chat_server-test STATIC ${CHAT_SERVER_SOURCE})
	target_link_libraries(chat_server-test PUBLIC asio)	

	add_executable(server_test testchatserver.cpp)
	target_link_libraries(server_test PRIVATE chat_server-test ws2_32)
endif()
