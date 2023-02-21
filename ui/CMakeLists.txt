cmake_minimum_required(VERSION 3.2)

project(chat_ui)

option(UI_TEST "Builds only ui" TRUE)

find_package(Qt6 REQUIRED COMPONENTS Qt6::Core)
find_package(Qt6 REQUIRED COMPONENTS Qt6::Widgets)
find_package(Qt6 REQUIRED COMPONENTS Qt6::Gui)

if (UI_TEST)	
	add_executable(ui-test tmain.cpp ui.cpp ui.hpp);

	target_link_libraries(ui-test PRIVATE Qt6::Core)
	target_link_libraries(ui-test PRIVATE Qt6::Widgets)
	target_link_libraries(ui-test PRIVATE Qt6::Gui)
else ()
	add_library(ui-lib ui.cpp ui.hpp)		

	target_link_libraries(ui-lib PRIVATE Qt6::Core)
	target_link_libraries(ui-lib PRIVATE Qt6::Widgets)
	target_link_libraries(ui-lib PRIVATE Qt6::Gui)
endif()
