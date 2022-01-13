#pragma once

#include <string>

struct GLFWwindow;
typedef void (*GLFWkeyfun)(GLFWwindow*, int, int, int, int);

class Window
{
public:
    Window(unsigned int width, unsigned int height, const std::string& title);
    ~Window();

    void update();
    void getFramebufferSize(int& width, int& height) const;
    void registerKeyEvent(GLFWkeyfun fun);

    int shouldClose();

    static void exitKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
    GLFWwindow* window;
};
