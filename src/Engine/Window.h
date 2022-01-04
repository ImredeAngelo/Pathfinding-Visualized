#pragma once

#include <string>
#include <glad/glad.h>

struct GLFWwindow;

class Window
{
    GLFWwindow *window;

    int width;
    int height;

    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;

public:
    Window(int height, int width, std::string&& title);
    ~Window();

    bool closed();
    void update();
};

#pragma clang diagnostic pop