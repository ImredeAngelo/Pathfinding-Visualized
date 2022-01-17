#pragma once

#include "Event.h"

class WindowResizeEvent final : public Event
{
    EVENT_CLASS(WindowResizeEvent, WindowResize);

public:
    WindowResizeEvent(int width, int height)
        : width(width), height(height) {}

    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    int width, height;
};

class WindowCloseEvent final : public Event
{
    EVENT_CLASS(WindowCloseEvent, WindowClose);

public:
    WindowCloseEvent() = default;
};