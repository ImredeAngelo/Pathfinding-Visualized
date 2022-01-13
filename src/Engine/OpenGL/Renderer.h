#pragma once

#include <Engine/Camera.h>
#include <Engine/Window.h>
#include <Engine/Vertex.h>

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

        unsigned int indexCount = 0;

        Vertex* buffer = nullptr;
        Vertex* bufferPtr = nullptr;

        unsigned int va, vb, ib, shader;

        void beginBatch();
    };
}

