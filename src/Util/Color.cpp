#include <iostream>
#include "Color.h"

// RGB 0-255
Color::Color(char r, char g, char b)
    : r(static_cast<float>(r)/255), g(static_cast<float>(g)/255), b(static_cast<float>(b)/255)
{}

// RGB 0-1
Color::Color(float r, float g, float b)
    : r(r), g(g), b(b)
{}

// Hexadecimal
Color::Color(unsigned int hex)
    : r((float)(hex >> 16)/255), g((float)((hex & 0x00FF00) >> 8)/255), b((float)(hex & 0x0000FF)/255)
{}
