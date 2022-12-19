cmake_minimum_required(VERSION 3.9.1)

project (raycast3d)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_STANDARD 14)
set (OpenGL_GL_PREFERENCE GLVND)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
set (sourceDir "${PROJECT_SOURCE_DIR}/src" "${PROJECT_SOURCE_DIR}/dependences/classes")

find_package(OpenGL REQUIRED)

set (libraries "OpenGL::GL" "OpenGL::OpenGL" "glfw" "dl")

set (source_files 
"${PROJECT_SOURCE_DIR}/src/main.cpp"
"${PROJECT_SOURCE_DIR}/src/glad.c"
"${PROJECT_SOURCE_DIR}/dependences/classes/sources/shaderProgram.cpp"
"${PROJECT_SOURCE_DIR}/dependences/classes/sources/vertexBuffer.cpp"
"${PROJECT_SOURCE_DIR}/dependences/classes/sources/vertexArray.cpp"
"${PROJECT_SOURCE_DIR}/dependences/classes/sources/indexBuffer.cpp"
"${PROJECT_SOURCE_DIR}/dependences/classes/sources/renderer.cpp"

)

add_executable(raycast3d ${source_files})
target_link_libraries(raycast3d PUBLIC ${libraries})
target_include_directories(raycast3d PRIVATE 
"${PROJECT_SOURCE_DIR}/dependences"
"${PROJECT_SOURCE_DIR}/dependences/glfw"
"${PROJECT_SOURCE_DIR}/dependences/classes/headers/"
"${PROJECT_SOURCE_DIR}/src"
)




