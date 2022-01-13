#include "Renderer.h"
#include "Shader.h"
#include <glad/glad.h>
#include <glm/gtx/transform.hpp>
#include <Engine/OpenGL/OpenGLHeaders.h>

constexpr size_t maxQuads = 1000;
constexpr size_t maxVertices = 4 * maxQuads;
constexpr size_t maxIndices = 6 * maxQuads;

OpenGL::Renderer::Renderer(const Window& window)
    : window(window)
{
    gladLoadGL();
    glClearColor(HEX_COLOR(0x262626), 1.0f);

    // TODO: Maybe use OOP for shader if render is class OR make renderer procedural
    shader = Shader::fromFile("basic");
    Shader::bind(shader);

    // Buffers
    glGenVertexArrays(1, &va);
    glBindVertexArray(va);

    glGenBuffers(1, &vb);
    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glBufferData(GL_ARRAY_BUFFER, maxVertices * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, position));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, color));

    // Indices always follow the same pattern
    uint32_t indices[maxIndices];
    uint32_t offset = 0;

    for(auto i = 0; i < maxIndices; i += 6, offset += 4)
    {
        indices[i+0] = offset + 0;
        indices[i+1] = offset + 1;
        indices[i+2] = offset + 2;

        indices[i+3] = offset + 2;
        indices[i+4] = offset + 3;
        indices[i+5] = offset + 0;
    }

    glGenBuffers(1, &ib);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, maxIndices * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    // Quad Buffer
    buffer = new Vertex[maxVertices];
    bufferPtr = buffer;
}

OpenGL::Renderer::~Renderer()
{
    delete[] buffer;

    Shader::destroy(shader);
}

void OpenGL::Renderer::beginFrame()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Set viewport
    int width, height;
    window.getFramebufferSize(width, height);
    camera.setProjection(width, height);
    glViewport(0, 0, width, height);

    // TODO: Only update when camera moves?
    glm::mat4 model = glm::translate(glm::vec3(0, 0, 0));
    Shader::setUniformMat4(shader, "u_MVP", camera.getViewMatrix() * model);

    beginBatch();
}

void OpenGL::Renderer::endFrame()
{
    auto size = (uint8_t*)bufferPtr - (uint8_t*)buffer;

    glBindVertexArray(va);
    glBufferSubData(GL_ARRAY_BUFFER, 0, size, buffer);

    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
}

void OpenGL::Renderer::drawQuad(float x, float y, float size, unsigned int color)
{
    if(indexCount >= maxIndices - 6)
    {
        endFrame();
        beginBatch();
    }

    bufferPtr->position = { x, y };
    bufferPtr->color = { HEX_COLOR(color) };
    bufferPtr++;

    bufferPtr->position = { x + size, y };
    bufferPtr->color = { HEX_COLOR(color) };
    bufferPtr++;

    bufferPtr->position = { x + size, y + size };
    bufferPtr->color = { HEX_COLOR(color) };
    bufferPtr++;

    bufferPtr->position = { x, y + size };
    bufferPtr->color = { HEX_COLOR(color) };
    bufferPtr++;

    indexCount += 6;
}

void OpenGL::Renderer::beginBatch()
{
    bufferPtr = buffer;
    indexCount = 0;
}
