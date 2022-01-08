#pragma once

#include <vector>
#include <glad/glad.h>
#include <iostream>

namespace OpenGL {

    struct VertexBufferElement
    {
        unsigned int type;
        unsigned int count;
        unsigned char normalized;

        static unsigned int getSizeOfType(unsigned int type)
        {
            switch (type)
            {
                case GL_FLOAT:          return 4;
                case GL_UNSIGNED_INT:   return 4;
                default:                return 0;
            }
        }
    };

    class VertexBufferLayout
    {
    public:
        VertexBufferLayout();

        template <typename T>
        void push(unsigned int count);

        inline const std::vector<VertexBufferElement> getElements() const { return elements; }
        inline int getStride() const { return stride; }

    private:
        std::vector<VertexBufferElement> elements;
        unsigned int stride;
    };

}
