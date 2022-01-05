#pragma once

struct GLFWwindow;

namespace OpenGL
{
    class Context 
    {
    public:
        Context(GLFWwindow* window);

        void makeQuad();
        void draw();

    private:
        GLFWwindow* window;
        unsigned int buffer, program;
    };
}
