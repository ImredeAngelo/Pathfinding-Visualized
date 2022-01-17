cmake_minimum_required(VERSION 3.0)
project(AI)

set(CMAKE_CXX_STANDARD 17)

# Precompiled Headers
#target_precompile_headers(${CMAKE_PROJECT_NAME} PUBLIC pch.h)

# Third-Party Dependencies
add_subdirectory (vendor/glfw)
add_subdirectory (vendor/glad)
add_subdirectory (vendor/glm)

# Source Files
add_executable(AI src/main.cpp src/Pathfinding/AStar.cpp src/Pathfinding/AStar.h src/Pathfinding/Math/Math.cpp src/Pathfinding/Math/Math.h src/Pathfinding/Core/MinHeap.h src/Pathfinding/Core/Timer.cpp src/Pathfinding/Core/Timer.h src/Pathfinding/Grid.cpp src/Pathfinding/Grid.h src/Engine/OpenGL/Renderer.cpp src/Engine/OpenGL/Renderer.h src/Core/Camera.cpp src/Core/Camera.h src/Engine/Vertex.h src/Engine/Window.cpp src/Engine/Window.h src/Engine/OpenGL/OpenGLHeaders.h src/Engine/OpenGL/Shader.cpp src/Engine/OpenGL/Shader.h src/Pathfinding/Node.h src/Pathfinding/Maze.cpp src/Pathfinding/Maze.h src/Events/WindowEvent.h src/Core/Application.cpp src/Core/Application.h src/Events/Event.cpp src/Events/Event.h src/Events/KeyEvent.h src/Events/MouseEvent.h)

# Included Resources
configure_file(res/shaders/basic.frag res/shaders/basic.frag COPYONLY)
configure_file(res/shaders/basic.vert res/shaders/basic.vert COPYONLY)

# Intellisense
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC glfw/include)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC glm/glm glm/glm/gtc)
# target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC imgui)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src)

# Link Vendors
target_link_libraries(${CMAKE_PROJECT_NAME}
        glfw
        glad
        glm
)
