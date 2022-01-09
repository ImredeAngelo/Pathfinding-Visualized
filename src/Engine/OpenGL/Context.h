#pragma once

#include <Engine/Camera.h>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"

struct GLFWwindow;

namespace OpenGL {

    class Context 
    {
    public:
        explicit Context(GLFWwindow* window);
        ~Context();

        void draw(Camera& camera);
        void makeQuad();
        void makeGrid(unsigned int n, float size);

    private:
        GLFWwindow* window;
        Renderer renderer;
        VertexArray* va;
        VertexBuffer* vb;
        IndexBuffer* ib;
        Shader* shader;
    };

}
