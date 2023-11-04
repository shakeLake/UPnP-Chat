cmake_minimum_required(VERSION 3.2...3.5)

project(chat)

add_subdirectory("../upnp" "upnp-build")

find_package(Threads REQUIRED)

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

add_library(asio INTERFACE)

target_include_directories(asio INTERFACE "${CMAKE_SOURCE_DIR}/third-party/asio-1.24.0/include")
target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)
target_link_libraries(asio INTERFACE Threads::Threads)

set(CHAT_SERVER_SOURCE 
	"include/sslinit.hpp"
	sslinit.cpp
	"include/default.hpp"
	data.cpp
	"include/data.hpp"
	filehandler.cpp
	"include/filehandler.hpp"
	server.cpp
	"include/server.hpp"
	client.cpp
	"include/client.hpp"
	clientcore.cpp
	"include/clientcore.hpp"
	"include/errorcodes.hpp"
)

add_library(upnp_chat-static STATIC ${CHAT_SERVER_SOURCE})

target_link_libraries(upnp_chat-static PUBLIC upnp-static)
target_link_libraries(upnp_chat-static PUBLIC OpenSSL::SSL)
target_link_libraries(upnp_chat-static PUBLIC OpenSSL::Crypto)


if (WIN32)
	target_link_libraries(upnp_chat-static PUBLIC asio ws2_32)
endif()

if (UNIX)
	target_link_libraries(upnp_chat-static PUBLIC asio)
endif()