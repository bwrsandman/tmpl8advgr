file(GLOB imgui_sources *.cpp examples/imgui_impl_glfw.cpp examples/imgui_impl_opengl3.cpp)
file(GLOB imgui_headers *.h examples/imgui_impl_glfw.h examples/imgui_impl_opengl3.h)
add_library(imgui STATIC ${imgui_sources} ${imgui_headers})
target_link_libraries(imgui PRIVATE glfw glad)
target_include_directories(imgui
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/examples
)
target_compile_definitions(imgui PRIVATE IMGUI_IMPL_OPENGL_LOADER_GLAD)
