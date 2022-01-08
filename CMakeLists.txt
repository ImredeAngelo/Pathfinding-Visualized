cmake_minimum_required(VERSION 3.8)
project(AI)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory (vendor/glfw)
add_subdirectory (vendor/glad)

add_executable(AI src/main.cpp src/Engine/Window.cpp src/Engine/Window.h src/Pathfinding/AStar.cpp src/Pathfinding/AStar.h src/Math/Math.cpp src/Math/Math.h src/Core/MinHeap.h src/Core/Maze.cpp src/Core/Maze.h src/Core/Timer.cpp src/Core/Timer.h src/Pathfinding/Grid.cpp src/Pathfinding/Grid.h src/Engine/OpenGL/Context.cpp src/Engine/OpenGL/Context.h src/Engine/OpenGL/Shaders.h src/Engine/OpenGL/Renderer.cpp src/Engine/OpenGL/Renderer.h src/Engine/OpenGL/VertexBuffer.cpp src/Engine/OpenGL/VertexBuffer.h src/Engine/OpenGL/IndexBuffer.cpp src/Engine/OpenGL/IndexBuffer.h src/Engine/OpenGL/VertexArray.cpp src/Engine/OpenGL/VertexArray.h src/Engine/OpenGL/VertexBufferLayout.h src/Engine/OpenGL/Vertex.h src/Engine/OpenGL/VertexBufferLayout.cpp)

# Include resources
FILE(COPY res DESTINATION .)

# Intellisense
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC glfw/include)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src)

# Link vendors
target_link_libraries(${CMAKE_PROJECT_NAME}
        glfw
        glad
)