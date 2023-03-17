cmake_minimum_required(VERSION 3.2)

project(chat_ui)

add_subdirectory("../chat" "chat-build")

# union
option(CDIALOG_TEST "Builds cdialog test" FALSE)
option(MCDIALOG_TEST "Builds mcdialog test" FALSE)
option(UI_TEST "Builds ui test" FALSE)
option(UI "Default" TRUE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:/Program Files/Qt/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)

if (CDIALOG_TEST)	
	add_library(cdialog-lib STATIC connectiondialog.cpp "include/connectiondialog.hpp")

	target_link_libraries(cdialog-lib PUBLIC Qt6::Core)
	target_link_libraries(cdialog-lib PUBLIC Qt6::Widgets)
	target_link_libraries(cdialog-lib PUBLIC Qt6::Gui)	

	add_executable(cdialog-test testdialog.cpp)

	target_link_libraries(cdialog-test PRIVATE cdialog-lib)
endif()

if (MCDIALOG_TEST)	
	add_library(mcdialog-lib STATIC makeconnectiondialog.cpp "/include/makeconnectiondialog.hpp")

	target_link_libraries(mcdialog-lib PUBLIC Qt6::Core)
	target_link_libraries(mcdialog-lib PUBLIC Qt6::Widgets)
	target_link_libraries(mcdialog-lib PUBLIC Qt6::Gui)

	add_executable(mcdialog-test testdialog.cpp)

	target_link_libraries(mcdialog-test PRIVATE mcdialog-lib)
endif()

if (UI_TEST)
	# ui | dialogs | design
	set(APP_SOURCE
		ui.cpp
		"include/ui.hpp"
		connectiondialog.cpp
		"include/connectiondialog.hpp"
		makeconnectiondialog.cpp
		"include/makeconnectiondialog.hpp"
		design.cpp
		"include/design.hpp"
	)

	add_library(app-lib STATIC ${APP_SOURCE})

	target_link_libraries(app-lib PUBLIC Qt6::Core)
	target_link_libraries(app-lib PUBLIC Qt6::Widgets)
	target_link_libraries(app-lib PUBLIC Qt6::Gui)
	
	add_executable(ui-test testui.cpp)

	target_link_libraries(ui-test PRIVATE app-lib)
endif()

if (UI)
	# ui | dialogs | design
	set(APP_SOURCE
		ui.cpp
		"include/ui.hpp"
		connectiondialog.cpp
		"include/connectiondialog.hpp"
		makeconnectiondialog.cpp
		"include/makeconnectiondialog.hpp"
		design.cpp
		"include/design.hpp"
		acceptdialog.cpp
		"include/acceptdialog.hpp"
		errordialog.cpp
		"include/errordialog.hpp"
	)

	add_library(app-lib STATIC ${APP_SOURCE})

	target_link_libraries(app-lib PUBLIC Qt6::Core)
	target_link_libraries(app-lib PUBLIC Qt6::Widgets)
	target_link_libraries(app-lib PUBLIC Qt6::Gui)
	target_link_libraries(app-lib PUBLIC upnp_chat-static)
	
	add_executable(app main.cpp)

	target_link_libraries(app PRIVATE app-lib)
endif()
