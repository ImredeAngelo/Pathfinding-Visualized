cmake_minimum_required(VERSION 3.20)
project(AI)

set(CMAKE_CXX_STANDARD 20)

add_executable(AI src/main.cpp src/Engine/Window.cpp src/Engine/Window.h src/Pathfinding/AStar.cpp src/Pathfinding/AStar.h src/Math/Math.cpp src/Math/Math.h src/Core/MinHeap.h src/Core/Maze.cpp src/Core/Maze.h src/Core/Timer.cpp src/Core/Timer.h)
