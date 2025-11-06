cmake_minimum_required(VERSION 3.16)
project(Gamepad-Capture LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS
    Widgets
    Core
    Gui
    Network
)

find_path(OPENH264_INCLUDE_DIR wels/codec_api.h)
find_library(OPENH264_LIBRARY openh264)
add_library(OpenH264::OpenH264 UNKNOWN IMPORTED)
set_target_properties(OpenH264::OpenH264 PROPERTIES
    IMPORTED_LOCATION ${OPENH264_LIBRARY}
    INTERFACE_INCLUDE_DIRECTORIES ${OPENH264_INCLUDE_DIR})

qt_standard_project_setup()
qt_add_executable(${PROJECT_NAME}
    src/main.cpp
    src/ui/main_window.cpp
    src/ui/main_container.cpp
    src/video/video_window.cpp
    src/video/video_worker.cpp
    src/video/video_decoder.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    src
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::Core
    Qt6::Gui
    Qt6::Network

    OpenH264::OpenH264
)
install(TARGETS ${PROJECT_NAME})