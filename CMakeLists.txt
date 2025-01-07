cmake_minimum_required(VERSION 3.12)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

file(GLOB_RECURSE
    OPENGL_MOLECULES_RESOURCES
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    CONFIGURE_DEPENDS

    ${CMAKE_CURRENT_SOURCE_DIR}/cmls/**.cml
    ${CMAKE_CURRENT_SOURCE_DIR}/**.frag
    ${CMAKE_CURRENT_SOURCE_DIR}/**.vert
    ${CMAKE_CURRENT_SOURCE_DIR}/textures/**.png
    ${CMAKE_CURRENT_SOURCE_DIR}/molecules_list.txt
)

foreach(OPENGL_MOLECULES_RESOURCE_FILE ${OPENGL_MOLECULES_RESOURCES})
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${OPENGL_MOLECULES_RESOURCE_FILE}
        COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/${OPENGL_MOLECULES_RESOURCE_FILE}
            ${CMAKE_CURRENT_BINARY_DIR}/${OPENGL_MOLECULES_RESOURCE_FILE}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${OPENGL_MOLECULES_RESOURCE_FILE}
  )
endforeach()

list(TRANSFORM OPENGL_MOLECULES_RESOURCES PREPEND ${CMAKE_CURRENT_BINARY_DIR}/)



add_executable(opengl-molecules
    cylinder.h
    main.cpp
    ryan_atom.h
    ryan_bond.h
    ryan_camera.h
    ryan_camera.cpp
    ryan_light.h
    ryan_matrix.h
    ryan_molecule.h
    ryan_sphere.h
    ryan_vector.h
    Shader.h
    Shader.cpp
    SkyBox.h
    SkyBox.cpp
    pugixml.hpp
    pugixml.cpp
    ${OPENGL_MOLECULES_RESOURCES}
)
target_link_libraries(opengl-molecules PRIVATE SOIL GLUT::GLUT GLEW::GLEW OpenGL::GL)
# target_include_directories(opengl-molecules PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../libSOIL)
