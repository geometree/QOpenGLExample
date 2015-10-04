project(viewer)

cmake_minimum_required(VERSION 2.8.11)

find_package(OpenGL REQUIRED)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Widgets REQUIRED)
add_definitions(${Qt5Core_DEFINITIONS})
add_definitions(${Qt5Gui_DEFINITIONS})
add_definitions(${Qt5Network_DEFINITIONS})
add_definitions(${Qt5OpenGL_DEFINITIONS})
add_definitions(${Qt5Widgets_DEFINITIONS})

set(CMAKE_CXX_FLAGS "-Wall -std=c++0x ${Qt5Core_EXECUTABLE_COMPILE_FLAGS} ${Qt5Gui_EXECUTABLE_COMPILE_FLAGS} ${Qt5Network_EXECUTABLE_COMPILE_FLAGS} ${Qt5OpenGL_EXECUTABLE_COMPILE_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}" CACHE STRING "Flags used by the compiler during all build types.")

include_directories(
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5GUI_INCLUDE_DIRS}
    ${Qt5Network_INCLUDE_DIRS}
    ${Qt5OpenGL_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIR}
)

qt5_wrap_cpp(gui_moc_srcs
    MyGLWidget.hpp
    MyGLWindow.hpp
)

set(gui_srcs
    ${gui_moc_srcs}
    MyGLWidget.cpp
    MyGLWindow.cpp
    main.cpp
)

add_executable(qt_opengl_test ${gui_srcs})

target_link_libraries(qt_opengl_test
    ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES} ${Qt5OpenGL_LIBRARIES}
    ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
)
