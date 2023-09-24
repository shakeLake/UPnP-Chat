cmake_minimum_required(VERSION 3.2...3.5)

project(chat_ui)

add_subdirectory("../chat" "chat-build")

if (CMAKE_BUILD_TYPE STREQUAL "Release")
	set(CMAKE_WIN32_EXECUTABLE TRUE)
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)

# ui | dialogs | design
set(APP_SOURCE
	ui.cpp
	"include/ui.hpp"
	"dialogs/connectiondialog.cpp"
	"dialogs/include/connectiondialog.hpp"
	"dialogs/makeconnectiondialog.cpp"
	"dialogs/include/makeconnectiondialog.hpp"
	"dialogs/alreadyopened.cpp"
	"dialogs/include/alreadyopened.hpp"
	design.cpp
	"include/design.hpp"
	"dialogs/errordialog.cpp"
	"dialogs/include/errordialog.hpp"
)

add_library(app-lib STATIC ${APP_SOURCE})

target_link_libraries(app-lib PUBLIC Qt6::Core)
target_link_libraries(app-lib PUBLIC Qt6::Widgets)
target_link_libraries(app-lib PUBLIC Qt6::Gui)
target_link_libraries(app-lib PUBLIC upnp_chat-static)

add_executable(Uchat app.qrc main.cpp)

target_link_libraries(Uchat PRIVATE app-lib)
