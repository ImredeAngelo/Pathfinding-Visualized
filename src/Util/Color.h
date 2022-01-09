#pragma once

class Color
{
public:
    Color(char r, char g, char b);
    Color(float r, float g, float b);
    Color(unsigned int hex);

    const float r;
    const float g;
    const float b;
};
