#pragma once

#include <Engine/OpenGL/Context.h>
#include "Camera.h"

struct GLFWwindow;

class Application
{
public:
    Application(int width, int height, const std::string& title);
    ~Application();

    void run();
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
    int width, height;

    OpenGL::Context* context;
    GLFWwindow* window;
    Camera camera;
};
