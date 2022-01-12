#pragma once

struct Vertex
{
    glm::vec2 position = {};
    glm::vec3 color = {};

    Vertex(const glm::vec2& position, unsigned int color)
        : position(position), color({})
    {
        this->color[0] = (float)(color >> 16)/255;
        this->color[1] = (float)((color >> 8) & 0xFF)/255;
        this->color[2] = (float)(color & 0xFF)/255;
    }

    Vertex(float x, float y, unsigned int color) : Vertex({ x, y }, color) {}
};
