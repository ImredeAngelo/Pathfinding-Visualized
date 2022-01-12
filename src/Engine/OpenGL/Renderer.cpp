#include "Renderer.h"
#include "Shader.h"
#include <glad/glad.h>
#include <Engine/Vertex.h>
#include <glm/gtx/transform.hpp>
#include <Engine/OpenGLHeaders.h>

constexpr size_t maxQuads = 1000;
constexpr size_t maxVertices = 4 * maxQuads;
constexpr size_t maxIndices = 6 * maxQuads;

OpenGL::Renderer::Renderer(const Window& window)
    : window(window)//, vb(sizeof(Vertex)), shader("basic")
{
    gladLoadGL();
    glClearColor(HEX_COLOR(0x9400D3), 1.0f);

    // TODO: Maybe use OOP for shader
    shader = Shader::fromFile("basic");
    Shader::bind(shader);

    // Indices always follow the same pattern
    uint32_t indices[maxIndices];
    uint32_t offset = 0;

    for(auto i = 0; i < maxIndices; i += 6, offset += 4)
    {
        indices[i+0] = offset + 0;
        indices[i+1] = offset + 1;
        indices[i+2] = offset + 2;

        indices[i+3] = offset + 3;
        indices[i+4] = offset + 4;
        indices[i+5] = offset + 0;
    }

//    ib = IndexBuffer(indices, maxIndices);
//
//    // Set layout
//    VertexBufferLayout layout;
//    layout.push<float>(2);
//    layout.push<float>(3);
//    va.addBuffer(vb, layout);
}

OpenGL::Renderer::~Renderer()
{
    Shader::destroy(shader);
}

void OpenGL::Renderer::beginFrame()
{
    glClear(GL_COLOR_BUFFER_BIT);
//    shader.bind();

    // Set viewport
    int width, height;
    window.getFramebufferSize(width, height);
    glViewport(0, 0, width, height);
    camera.setProjection(width, height);

    // Set MVP
    // TODO: Only update when camera moves?
    glm::mat4 model = glm::translate(glm::vec3(100, 100, 0));
//    shader.setUniformMat4("u_MVP", camera.getViewMatrix() * model);

    beginBatch();
}

void OpenGL::Renderer::endFrame()
{
    // ib.getCount()
    glDrawElements(GL_TRIANGLES, 0, GL_UNSIGNED_INT, nullptr);
}

void OpenGL::Renderer::drawQuad(float x, float y, float size, unsigned int color)
{

}

void OpenGL::Renderer::beginBatch()
{

}
