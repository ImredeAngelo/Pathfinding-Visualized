#pragma once

namespace OpenGL {

    class VertexBuffer {
    public:
        VertexBuffer(const void* data, unsigned int size);
        VertexBuffer(unsigned int size);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;

    private:
        unsigned int rendererID;
    };

}
