#pragma once

struct Vertex
{
    float x, y;
    float r, g, b, a;

    Vertex(float x, float y, int color)
        : x(x), y(y), a(1.0f)
    {
        r = (float) (color >> 16)/255;
        g = (float)((color >> 8) & 0xFF)/255;
        b = (float)((color & 0xFF))/255;
    }
};
