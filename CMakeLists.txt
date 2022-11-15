cmake_minimum_required(VERSION 3.23)
project(OpenGLEngine)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES src/main.cpp src/deps/GLAD/glad.c src/OGL/Shaders.h src/OGL/Shaders.cpp src/OGL/VBO.cpp src/OGL/VBO.h
        src/OGL/EBO.cpp src/OGL/EBO.h src/OGL/VAO.cpp src/OGL/VAO.h src/stb_image.cpp src/OGL/Texture.cpp src/OGL/Texture.h
        src/Engine/Game.cpp src/Engine/Game.h src/main.cpp src/Engine/Scene.cpp src/Engine/Scene.h src/Engine/Utilities.h src/Engine/Object.h src/Engine/Utilities.cpp src/Engine/Sprite.cpp src/Engine/Sprite.h src/Engine/Rect.h src/Engine/CursorSprite.cpp src/Engine/CursorSprite.h src/Engine/FileManager.cpp src/Engine/FileManager.h)

add_executable( OpenGLEngine ${SOURCE_FILES})


file(COPY shaders DESTINATION ./)
file(COPY textures DESTINATION ./)
file(COPY src/Assets/config.json DESTINATION ./)
target_link_libraries(OpenGLEngine dl glfw)