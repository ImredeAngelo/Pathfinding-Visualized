#pragma once

#include <string>

struct GLFWwindow;

class Window
{
public:
    Window(unsigned int width, unsigned int height, const std::string& title);
    ~Window();

    void update();
    void getFramebufferSize(int& width, int& height) const;

    int shouldClose();

    // static void exitKeyCallback();

private:
    GLFWwindow* window;
};
