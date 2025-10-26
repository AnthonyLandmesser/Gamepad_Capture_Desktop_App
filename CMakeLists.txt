cmake_minimum_required(VERSION 3.16)
project(Gamepad-Capture LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS
    Widgets
    Core
    Gui
    Network
)

qt_standard_project_setup()
qt_add_executable(${PROJECT_NAME}
    src/main.cpp
    src/ui/main_window.cpp
    # src/ui/main_contianer.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::Core
    Qt6::Gui
    Qt6::Network
)
install(TARGETS ${PROJECT_NAME})