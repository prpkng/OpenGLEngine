cmake_minimum_required(VERSION 3.23)
project(OpenGLEngine)

set(CMAKE_CXX_STANDARD 17)

file(GLOB PROJ_src
        "src/OGL/*.h"
        "src/OGL/*.cpp"
        "src/Engine/*.h"
        "src/Engine/*.cpp"
        "src/Engine/Components/*.h"
        "src/Engine/Components/*.cpp"
        "src/Engine/Objects/*.h"
        "src/Engine/Objects/*.cpp"
)

file(GLOB OGL_src
        "src/OGL/*.h"
        "src/OGL/*.cpp"
        )

set(SOURCE_FILES src/main.cpp src/glad.c src/stb_image.cpp ${PROJ_src})

include_directories(${PROJECT_SOURCE_DIR}/GLFW/include)

link_directories(${PROJECT_SOURCE_DIR}/GLFW/lib-mingw-w64)


add_executable( OpenGLEngine ${SOURCE_FILES})

file(COPY shaders DESTINATION ./)
file(COPY textures DESTINATION ./)
file(COPY src/Assets/config.json DESTINATION ./)

target_link_libraries(OpenGLEngine glfw3)