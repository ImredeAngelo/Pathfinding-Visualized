#include "VertexBufferLayout.h"

namespace OpenGL {

    VertexBufferLayout::VertexBufferLayout() : stride(0) { }

    template <>
    void VertexBufferLayout::push<float>(unsigned int count)
    {
        elements.push_back({ GL_FLOAT, count, GL_FALSE });
        stride += VertexBufferElement::getSizeOfType(GL_FLOAT) * count;
    }

    template <>
    void VertexBufferLayout::push<unsigned int>(unsigned int count)
    {
        elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
        stride += VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT) * count;
    }
};

