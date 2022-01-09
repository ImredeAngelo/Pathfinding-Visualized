#include "Renderer.h"
#include <glad/glad.h>

void OpenGL::Renderer::draw(const OpenGL::VertexArray *vertexArray, const OpenGL::IndexBuffer *indexBuffer, const Shader *shader) const
{
    shader->bind();
    vertexArray->bind();
//    indexBuffer->bind();

    // TODO: GL_QUADS
    glDrawElements(GL_TRIANGLES, indexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);
}

void OpenGL::Renderer::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGL::Renderer::drawSquare() const
{

}

