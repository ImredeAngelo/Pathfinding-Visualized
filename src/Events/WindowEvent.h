#pragma once

#include "Event.h"

namespace Events {

    class WindowResizeEvent final : Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : width(width), height(height) {}

        unsigned int GetWidth() const { return width; }
        unsigned int GetHeight() const { return height; }

    private:
        unsigned int width, height;
    };

    class WindowCloseEvent final : Event
    {
    public:
        WindowCloseEvent() = default;
    };

}

