#pragma once

#include <Core/Camera.h>
#include <Engine/Window.h>
#include <Engine/Vertex.h>

namespace OpenGL {

    /**
     * Only one window will ever be rendered
     */
    class Renderer
    {
    public:
        explicit Renderer(const Camera& camera);
        ~Renderer();

        void beginFrame();
        void endFrame();

        void drawQuad(float x, float y, float size, unsigned int color);

        void onEvent(Event&);
        void onWindowResize(WindowResizeEvent&);

    private:
        const Camera& camera;

        unsigned int indexCount = 0;

        Vertex* buffer = nullptr;
        Vertex* bufferPtr = nullptr;

        unsigned int va, vb, ib, shader;

        void beginBatch();
    };
}

