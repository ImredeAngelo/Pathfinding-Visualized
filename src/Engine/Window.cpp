#include "Window.h"
#include <GLFW/glfw3.h>

Window::Window(int height, int width, std::string&& title)
    : width(width), height(height), window(nullptr)
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
    // context->swapBuffers();
    context->draw();
    glfwPollEvents();
}
