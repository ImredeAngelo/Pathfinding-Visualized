#pragma once

struct Node
{
    Node(float x, float y) : x(x), y(y) {};
    Node(float x, float y, bool walkable) : x(x), y(y), color(walkable ? WALKABLE : BLOCKED) {};

    float x = 0, y = 0;

    // Yes, color is a stupid name used in some textbooks but in this case each state is
    // also coincidentally tightly coupled to a color when rendered (this is usually a cost-flag)
    enum uint32_t {
        WALKABLE    = 0xCD7F32,
        BLOCKED     = 0x262626,
    } color = WALKABLE;
};