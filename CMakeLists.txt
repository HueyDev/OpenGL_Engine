cmake_minimum_required(VERSION 2.9)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set (CMAKE_CXX_STANDARD 11)

project(OGLE)

add_executable(OGLE src/main.cpp external_includes/glad/src/glad.c src/fileLoader.cpp)

include_directories(external_includes/glfw-3.3.4/include include external_includes/glad/include)

add_subdirectory(external_includes/glfw-3.3.4)
#find_package(glfw3 3.3 REQUIRED)

target_link_libraries(OGLE glfw ${CMAKE_DL_LIBS})

file(COPY shaders DESTINATION shaders)