cmake_minimum_required(VERSION 3.2)

project(chat_ui)

option(CDIALOG_TEST "Builds cdialog test" FALSE)
option(MCDIALOG_TEST "Builds mcdialog test" FALSE)
option(UI_TEST "Builds ui test" TRUE)

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
endif()

if (MCDIALOG_TEST)	
	add_executable(mcdialog-test tdialog.cpp makeconnectiondialog.cpp "include/makeconnectiondialog.hpp")

	target_link_libraries(mcdialog-test PRIVATE Qt6::Core)
	target_link_libraries(mcdialog-test PRIVATE Qt6::Widgets)
	target_link_libraries(mcdialog-test PRIVATE Qt6::Gui)
endif()

if (UI_TEST)
	add_library(design-lib design.cpp "include/design.hpp")	
	target_link_libraries(design-lib PRIVATE Qt6::Widgets)

	add_executable(ui-test tmain.cpp ui.cpp "include/ui.hpp")

	target_link_libraries(ui-test PRIVATE Qt6::Core)
	target_link_libraries(ui-test PRIVATE Qt6::Widgets)
	target_link_libraries(ui-test PRIVATE Qt6::Gui)
	target_link_libraries(ui-test PRIVATE design-lib)
endif()

#else ()
#	add_library(ui-lib ui.cpp "include/ui.hpp")		

#	target_link_libraries(ui-lib PRIVATE Qt6::Core)
#	target_link_libraries(ui-lib PRIVATE Qt6::Widgets)
#	target_link_libraries(ui-lib PRIVATE Qt6::Gui)
#endif()
