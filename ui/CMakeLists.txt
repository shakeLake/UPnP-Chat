cmake_minimum_required(VERSION 3.2)

project(chat_ui)

option(DIALOG_TEST "Builds dialog test" TRUE)
option(UI_TEST "Builds ui test" FALSE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS StateMachine)

if (DIALOG_TEST)	
	add_executable(dialog-test tdialog.cpp dialog.cpp "include/dialog.hpp")

	target_link_libraries(dialog-test PRIVATE Qt6::Core)
	target_link_libraries(dialog-test PRIVATE Qt6::Widgets)
	target_link_libraries(dialog-test PRIVATE Qt6::Gui)
	target_link_libraries(dialog-test PRIVATE Qt6::StateMachine)
elseif (UI_TEST)
#	add_executable(ui-test tmain.cpp ui.cpp "include/ui.hpp")

#	target_link_libraries(ui-test PRIVATE Qt6::Core)
#	target_link_libraries(ui-test PRIVATE Qt6::Widgets)
#	target_link_libraries(ui-test PRIVATE Qt6::Gui)
else ()
#	add_library(ui-lib ui.cpp "include/ui.hpp")		

#	target_link_libraries(ui-lib PRIVATE Qt6::Core)
#	target_link_libraries(ui-lib PRIVATE Qt6::Widgets)
#	target_link_libraries(ui-lib PRIVATE Qt6::Gui)
endif()
