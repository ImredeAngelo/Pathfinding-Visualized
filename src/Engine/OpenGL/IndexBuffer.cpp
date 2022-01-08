#include <glad/glad.h>
#include "IndexBuffer.h"

OpenGL::IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    : count(count)
{
    glGenBuffers(1, &rendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

OpenGL::IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &rendererID);
}

void OpenGL::IndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
}

void OpenGL::IndexBuffer::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
