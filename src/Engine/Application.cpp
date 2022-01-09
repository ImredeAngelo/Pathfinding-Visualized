#include "Application.h"
#include <GLFW/glfw3.h>

Application::Application(int width, int height, const std::string& title)
    : width(width), height(height)
{
    if(!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if(!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, keyCallback);

    context = new OpenGL::Context(window);
    context->makeQuad();
//    context->makeGrid(10, 100);
}

Application::~Application()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Application::run()
{
    if(!window)
        return;

    while (!glfwWindowShouldClose(window))
    {
        context->draw(camera);
        glfwPollEvents();
    }
}

void Application::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
