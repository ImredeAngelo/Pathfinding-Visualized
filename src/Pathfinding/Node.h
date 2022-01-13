#pragma once

struct Node
{


    Node(float x, float y) : x(x), y(y) {};
    Node(float x, float y, bool walkable) : x(x), y(y), color(walkable ? WALKABLE : BLOCKED) {};

    float x = 0, y = 0;

    // Yes, color is a stupid name used in some textbooks but in this case each state is
    // also coincidentally tightly coupled to a color when rendered
    enum uint8_t {
        WALKABLE    = 0xCD7F32,
        BLOCKED     = 0x1C1C1C,
    } color = WALKABLE;
};