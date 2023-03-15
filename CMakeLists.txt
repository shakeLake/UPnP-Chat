cmake_minimum_required(VERSION 3.2)

project(upnp_chat)

option(CHAT_TEST "Build chat tests" FALSE)
option(Default "Default" TRUE)

if (CHAT_TEST)
	add_subdirectory("chat" "chat-build")
endif()

if (Default)
	add_subdirectory("app" "app-build")
endif()
