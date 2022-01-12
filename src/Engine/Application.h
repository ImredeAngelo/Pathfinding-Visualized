#pragma once

#include "Camera.h"
#include <string>

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

    GLFWwindow* window;
    Camera camera;
};
