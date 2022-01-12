#include <GLFW/glfw3.h>
#include <cstdlib>
#include "Window.h"

#define ERROR_INIT_GLFW     0xAA
#define ERROR_INIT_WINDOW   0xAB

Window::Window(unsigned int width, unsigned int height, const std::string& title)
{
    if(!glfwInit())
        exit(ERROR_INIT_GLFW);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if(!window)
    {
        glfwTerminate();
        exit(ERROR_INIT_WINDOW);
    }

    glfwMakeContextCurrent(window);

    registerKeyEvent(exitKeyCallback);
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::update()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::getFramebufferSize(int &width, int &height) const
{
    glfwGetFramebufferSize(window, &width, &height);
}

void Window::registerKeyEvent(GLFWkeyfun callback)
{
    // TODO: Check if this only callbacks to a single function
    glfwSetKeyCallback(window, callback);
}

int Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::exitKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
