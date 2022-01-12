#pragma once

#include <Engine/Camera.h>
#include <Engine/Window.h>
#include "VertexArray.h"

namespace OpenGL {

    /**
     * Only one window will ever be rendered
     */
    class Renderer
    {
    public:
        explicit Renderer(const Window&);
        ~Renderer();

        void beginFrame();
        void endFrame();

        void drawQuad(float x, float y, float size, unsigned int color);

    private:
        const Window& window;

        Camera camera;
//        VertexArray va;
//        VertexBuffer vb;
//        IndexBuffer ib;
        unsigned int shader;

        void beginBatch();
    };
}

