#pragma once

#include "Event.h"

class KeyEvent : public Event
{
public:
    int getKey() const { return key; }

protected:
    KeyEvent(int key) : key(key) {};
    int key;
};

class KeyPressEvent final : public KeyEvent
{
    EVENT_TYPE(KeyPress);

public:
    KeyPressEvent(int key, int repeat) : KeyEvent(key), repeat(repeat) {};

    int getCount() const { return repeat; }

private:
    int repeat;
};

class KeyReleaseEvent final : public KeyEvent
{
    EVENT_TYPE(KeyRelease);

public:
    KeyReleaseEvent(int key) : KeyEvent(key) {};
};