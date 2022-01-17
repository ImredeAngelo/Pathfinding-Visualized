#pragma once

#include "Event.h"

class MouseButtonEvent : public Event
{
public:
    int getButton() const { return button; }

protected:
    MouseButtonEvent(int button)
            : button(button) {}

    int button;
};

/**
 * Contains what mouse button was pressed and if the button was pressed previously
 */
class MouseButtonPressEvent final : public MouseButtonEvent
{
    EVENT_TYPE(MouseButtonPressed)

public:
    MouseButtonPressEvent(int button, int repeats)
            : MouseButtonEvent(button), repeats(repeats) {};

    int getRepeatCount() const { return repeats; }

private:
    int repeats;
};

/**
 * Contains what mouse button was released
 */
class MouseButtonReleasedEvent final : public MouseButtonEvent
{
    EVENT_TYPE(MouseButtonReleased)

public:
    MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button) {};
};

/**
 * Contains the distance moved vertically and horizontally
 */
class MouseMovedEvent final : public Event
{
    EVENT_TYPE(MouseMoved)

public:
    MouseMovedEvent(const float x, const float y)
            : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

private:
    float x, y;
};

/**
 * Contains the distance scrolled
 */
class MouseScrolledEvent final : public Event
{
    EVENT_TYPE(MouseScrolled)

public:
    MouseScrolledEvent(const float ds)
            : ds(ds) {}

    float getDifference() const { return ds; }

private:
    float ds;
};