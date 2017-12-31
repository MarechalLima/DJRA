cmake_minimum_required(VERSION 3.9)
project(djra)

set(CMAKE_CXX_STANDARD 17)

include_directories(./)

add_executable(djra
        background_render.cpp
        main.cpp spheres.cpp spheres.hpp render.cpp render.hpp transition.cpp transition.hpp exit.cpp exit.hpp tutorial.cpp tutorial.hpp collision.cpp collision.hpp)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)
find_package(OpenCV REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(djra ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${OpenCV_LIBS})