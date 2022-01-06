#include "Window.h"
#include <GLFW/glfw3.h>

Window::Window(int width, int height, std::string&& title)
    : width(width), height(height)
{
    if(!glfwInit())
        exit(EXIT_FAILURE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if(!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    context = new OpenGL::Context(window);
    context->makeQuad();
}

Window::Window(std::string&& title)
{
    // TODO
    if (!glfwInit())
        exit(EXIT_FAILURE);

    int xpos, ypos;
    
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    glfwGetMonitorWorkarea(monitor, &xpos, &ypos, &width, &height);
    window = glfwCreateWindow(width, height, title.c_str(), monitor, nullptr);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    context = new OpenGL::Context(window);
    context->makeQuad();
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Window::closed()
{
    return static_cast<bool>(glfwWindowShouldClose(window));
}

void Window::update()
{
    // TODO: Only draw if grid is updated!
    context->draw();
    glfwPollEvents();
}
