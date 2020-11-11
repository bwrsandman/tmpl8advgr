cmake_minimum_required(VERSION 3.16)
project(tmpl8advgr)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(OpenCL REQUIRED)
add_subdirectory(lib/FreeImage)
add_subdirectory(lib/glad)
add_subdirectory(lib/imgui)

add_executable(tmpl8advgr)
target_sources(tmpl8advgr
  PRIVATE
    game.h
    game.cpp
    surface.h
    surface.cpp
    template.h
    template.cpp
)
target_link_libraries(tmpl8advgr
  PRIVATE
    dl
    FreeImage
    glfw
    OpenGL::GL
    OpenCL::OpenCL
    imgui
    glad
)
target_compile_definitions(tmpl8advgr
  PRIVATE
    GLFW_USE_CHDIR=0
    # Default screen resolution
    SCRWIDTH=512
    SCRHEIGHT=384
)
