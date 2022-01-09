#pragma once

namespace OpenGL {

    class IndexBuffer {
    public:
        IndexBuffer(const unsigned int* data, unsigned int count);
        ~IndexBuffer();

        void bind() const;
        void unbind() const;

        inline unsigned int getCount() const { return count; }

    private:
        unsigned int rendererID;
        unsigned int count; // indices
    };

}