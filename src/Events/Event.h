#pragma once

namespace Events {

    enum class Type
    {
        None = 0,
        WindowClose, WindowResize,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    class Event
    {
    public:
    };

    void addCallback(const Type&);
    void callEvent(const Event&);
    void process();

}