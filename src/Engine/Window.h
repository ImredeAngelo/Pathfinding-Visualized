#pragma once

#include "OpenGL/Context.h"

#include <string>

class Window
{
    GLFWwindow* window;
    OpenGL::Context* context;

    int width;
    int height;

public:
    explicit Window(std::string&& title);
    Window(int height, int width, std::string&& title);
    ~Window();

    bool closed();
    void update();
};
