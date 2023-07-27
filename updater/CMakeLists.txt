cmake_minimum_required(VERSION 3.2)

project(Updater)

add_library(uptd STATIC update.cpp update.hpp)

add_executable(Updater up.cpp)

target_link_libraries(Updater PRIVATE uptd)