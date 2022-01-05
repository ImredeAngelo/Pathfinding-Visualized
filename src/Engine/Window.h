#pragma once

#include <Engine/OpenGL/Context.h>

#include <string>

class Window
{
    GLFWwindow* window;
    OpenGL::Context* context;

    int width;
    int height;

public:
    Window(int height, int width, std::string&& title);
    ~Window();

    bool closed();
    void update();
};
