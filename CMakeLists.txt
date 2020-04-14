cmake_minimum_required(VERSION 3.7.0)

project(cli_window)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(QTermWidget5 REQUIRED)

add_executable(cli_window cli_window.cpp)

target_link_libraries(cli_window Qt5::Widgets qtermwidget5)
