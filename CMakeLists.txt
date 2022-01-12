cmake_minimum_required(VERSION 3.8)
project(AI)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory (vendor/glfw)
add_subdirectory (vendor/glad)
add_subdirectory (vendor/glm)

add_executable(AI src/main.cpp src/Pathfinding/AStar.cpp src/Pathfinding/AStar.h src/Math/Math.cpp src/Math/Math.h src/Core/MinHeap.h src/Core/Maze.cpp src/Core/Maze.h src/Core/Timer.cpp src/Core/Timer.h src/Pathfinding/Grid.cpp src/Pathfinding/Grid.h src/Engine/OpenGL/Renderer.cpp src/Engine/OpenGL/Renderer.h src/Engine/Camera.cpp src/Engine/Camera.h src/Engine/Vertex.h src/Engine/Window.cpp src/Engine/Window.h src/Engine/OpenGL/OpenGLHeaders.h src/Engine/OpenGL/Shader.cpp src/Engine/OpenGL/Shader.h)

# Include resources
FILE(COPY res DESTINATION .)

# Intellisense
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC glfw/include)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC glm/glm glm/glm/gtc)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src)

# Link vendors
target_link_libraries(${CMAKE_PROJECT_NAME}
        glfw
        glad
        glm
)