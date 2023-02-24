cmake_minimum_required(VERSION 3.2)

project(chat_ui)

option(TESTs "Builds tests" TRUE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)

if (TESTs)	
#	add_executable(ui-test tmain.cpp ui.cpp "include/ui.hpp")

#	target_link_libraries(ui-test PRIVATE Qt6::Core)
#	target_link_libraries(ui-test PRIVATE Qt6::Widgets)
#	target_link_libraries(ui-test PRIVATE Qt6::Gui)

	add_executable(dialog-test tdialog.cpp dialog.cpp "include/dialog.hpp")

	target_link_libraries(dialog-test PRIVATE Qt6::Core)
	target_link_libraries(dialog-test PRIVATE Qt6::Widgets)
	target_link_libraries(dialog-test PRIVATE Qt6::Gui)
else ()
	add_library(ui-lib ui.cpp "include/ui.hpp")		

	target_link_libraries(ui-lib PRIVATE Qt6::Core)
	target_link_libraries(ui-lib PRIVATE Qt6::Widgets)
	target_link_libraries(ui-lib PRIVATE Qt6::Gui)
endif()
