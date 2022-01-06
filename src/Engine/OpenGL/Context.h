#pragma once

struct GLFWwindow;

namespace OpenGL
{
    class Context 
    {
    public:
        Context(GLFWwindow* window);
        ~Context();

        void makeQuad();
        void draw();

    private:
        GLFWwindow* window;
        unsigned int program;
    };
}
