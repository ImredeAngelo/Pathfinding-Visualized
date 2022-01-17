#pragma once

#include <string>

struct GLFWwindow;

class Window
{
public:
    Window(unsigned int width, unsigned int height, const std::string& title);
    ~Window();

    void update();

    int shouldClose();

private:
    GLFWwindow* window;
};
