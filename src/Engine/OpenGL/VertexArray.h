#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"

namespace OpenGL {

    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void addBuffer(const VertexBuffer*, const VertexBufferLayout&);
        void bind();
        void unbind();

    private:
        unsigned int rendererID;
    };

}