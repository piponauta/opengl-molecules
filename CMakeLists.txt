cmake_minimum_required(VERSION 3.12)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

add_executable(opengl-molecules
    main.cpp
    ryan_camera.h
    ryan_camera.cpp
    Shader.h
    Shader.cpp
    SkyBox.h
    SkyBox.cpp
    pugixml.hpp
    pugixml.cpp
)
target_link_libraries(opengl-molecules PRIVATE SOIL GLUT::GLUT GLEW::GLEW OpenGL::OpenGL)
# target_include_directories(opengl-molecules PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../libSOIL)
