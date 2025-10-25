cmake_minimum_required(VERSION 3.16)
project(Gamepad-Capture LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()
qt_add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
install(TARGETS ${PROJECT_NAME})