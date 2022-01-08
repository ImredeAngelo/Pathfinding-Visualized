#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

struct GLFWwindow;

namespace OpenGL {

    class Context 
    {
    public:
        explicit Context(GLFWwindow* window);
        ~Context();

        void makeQuad();
        void draw();

    private:
        GLFWwindow* window;
        VertexArray* va;
        VertexBuffer* vb;
        IndexBuffer* ib;
        unsigned int program;
    };

}
