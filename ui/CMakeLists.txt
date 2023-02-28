cmake_minimum_required(VERSION 3.2)

project(chat_ui)

option(CDIALOG_TEST "Builds cdialog test" FALSE)
option(MCDIALOG_TEST "Builds mcdialog test" TRUE)
option(UI_TEST "Builds ui test" FALSE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)

if (CDIALOG_TEST)	
	add_executable(cdialog-test tdialog.cpp connectiondialog.cpp "include/connectiondialog.hpp")

	target_link_libraries(cdialog-test PRIVATE Qt6::Core)
	target_link_libraries(cdialog-test PRIVATE Qt6::Widgets)
	target_link_libraries(cdialog-test PRIVATE Qt6::Gui)
elseif (MCDIALOG_TEST)	
	add_executable(mcdialog-test tdialog.cpp makeconnectiondialog.cpp "include/makeconnectiondialog.hpp")

	target_link_libraries(mcdialog-test PRIVATE Qt6::Core)
	target_link_libraries(mcdialog-test PRIVATE Qt6::Widgets)
	target_link_libraries(mcdialog-test PRIVATE Qt6::Gui)
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
