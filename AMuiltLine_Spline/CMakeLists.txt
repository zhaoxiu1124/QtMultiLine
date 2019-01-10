
cmake_minimum_required(VERSION 3.5)

add_definitions("-std=c++11")

project(line)

# QT 创建UI
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Charts CONFIG REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Charts)


set(BIN_NAME Splie)

file(GLOB project_src *.cpp *.cc *.ui)

add_executable(${BIN_NAME} ${project_src})

target_link_libraries(${BIN_NAME}
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Charts
)

