cmake_minimum_required(VERSION 3.2)

project(chat_ui)

# union
option(CDIALOG_TEST "Builds cdialog test" FALSE)
option(MCDIALOG_TEST "Builds mcdialog test" TRUE)
option(UI_TEST "Builds ui test" FALSE)
option(UI "Default" FALSE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:/Program Files/Qt/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)

if (CDIALOG_TEST)	
	add_library(cdialog-lib connectiondialog.cpp "include/connectiondialog.hpp")

	target_link_libraries(cdialog-lib PRIVATE Qt6::Core)
	target_link_libraries(cdialog-lib PRIVATE Qt6::Widgets)
	target_link_libraries(cdialog-lib PRIVATE Qt6::Gui)	

	add_executable(cdialog-test testdialog.cpp)

	target_link_libraries(cdialog-test PRIVATE cdialog-lib)
endif()

if (MCDIALOG_TEST)	
	add_library(mcdialog-lib makeconnectiondialog.cpp "${CMAKE_SOURCE_DIR}/include/makeconnectiondialog.hpp")

	target_link_libraries(mcdialog-lib PRIVATE Qt6::Core)
	target_link_libraries(mcdialog-lib PRIVATE Qt6::Widgets)
	target_link_libraries(mcdialog-lib PRIVATE Qt6::Gui)

	add_executable(mcdialog-test testdialog.cpp)

	target_link_libraries(mcdialog-test PRIVATE mcdialog-lib)
endif()

if (UI_TEST)
	add_library(design-lib design.cpp "include/design.hpp")	
	target_link_libraries(design-lib PRIVATE Qt6::Widgets)

	add_library(ui-lib ui.cpp "include/ui.hpp")

	target_link_libraries(ui-lib PRIVATE Qt6::Core)
	target_link_libraries(ui-lib PRIVATE Qt6::Widgets)
	target_link_libraries(ui-lib PRIVATE Qt6::Gui)
	target_link_libraries(ui-lib PRIVATE design-lib)
	
	add_library(cdialog-lib connectiondialog.cpp "include/connectiondialog.hpp")

	target_link_libraries(cdialog-lib PRIVATE Qt6::Core)
	target_link_libraries(cdialog-lib PRIVATE Qt6::Widgets)
	target_link_libraries(cdialog-lib PRIVATE Qt6::Gui)

	add_library(mcdialog-lib makeconnectiondialog.cpp "include/makeconnectiondialog.hpp")

	target_link_libraries(mcdialog-lib PRIVATE Qt6::Core)
	target_link_libraries(mcdialog-lib PRIVATE Qt6::Widgets)
	target_link_libraries(mcdialog-lib PRIVATE Qt6::Gui)
	
	add_executable(ui-test testui.cpp)

	target_link_libraries(ui-test PRIVATE ui-lib)
	target_link_libraries(ui-test PRIVATE cdialog-lib)
	target_link_libraries(ui-test PRIVATE mcdialog-lib)
endif()