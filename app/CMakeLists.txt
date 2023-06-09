cmake_minimum_required(VERSION 3.2)

project(chat_ui)

add_subdirectory("../chat" "chat-build")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)

# ui | dialogs | design
set(APP_SOURCE
	ui.cpp
	"include/ui.hpp"
	connectiondialog.cpp
	"include/connectiondialog.hpp"
	makeconnectiondialog.cpp
	"include/makeconnectiondialog.hpp"
	alreadyopened.cpp
	"include/alreadyopened.hpp"
	design.cpp
	"include/design.hpp"
	errordialog.cpp
	"include/errordialog.hpp"
)

add_library(app-lib STATIC ${APP_SOURCE})

target_link_libraries(app-lib PUBLIC Qt6::Core)
target_link_libraries(app-lib PUBLIC Qt6::Widgets)
target_link_libraries(app-lib PUBLIC Qt6::Gui)
target_link_libraries(app-lib PUBLIC upnp_chat-static)

add_executable(Uchat app.qrc main.cpp)

target_link_libraries(Uchat PRIVATE app-lib)
