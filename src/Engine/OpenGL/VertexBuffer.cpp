#include <glad/glad.h>
#include "VertexBuffer.h"
#include "Renderer.h"

OpenGL::VertexBuffer::VertexBuffer(const void *data, unsigned int size)
{
    glGenBuffers(1, &rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

OpenGL::VertexBuffer::VertexBuffer(unsigned int size)
{
    glGenBuffers(1, &rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
    glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}

OpenGL::VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &rendererID);
}

void OpenGL::VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, rendererID);
}

void OpenGL::VertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
