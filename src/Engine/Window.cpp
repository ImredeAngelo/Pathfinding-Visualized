#include <GLFW/glfw3.h>
#include <cstdlib>
#include <Events/Event.h>
#include <Events/WindowEvent.h>
#include <iostream>
#include <Events/KeyEvent.h>
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

    // Event Callbacks
    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) { Events::dispatch(WindowResizeEvent(width, height)); });
    glfwSetWindowCloseCallback(window, [](GLFWwindow* window) { Events::dispatch(WindowCloseEvent()); });

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        switch (action)
        {
            case GLFW_PRESS:    Events::dispatch(KeyPressEvent(key, 0)); break;
            case GLFW_REPEAT:   Events::dispatch(KeyPressEvent(key, 1)); break;
            case GLFW_RELEASE:  Events::dispatch(KeyReleaseEvent(key));  break;
            default: return;
        }
    });
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

int Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}