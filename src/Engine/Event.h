#pragma once

namespace Events {

    enum class Type
    {
        None = 0,
        WindowClose, WindowResize,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseScrolled
    };

//    enum Category
//    {
//        None        = 1 << 0,
//        Input       = 1 << 1,
//        Keyboard    = 1 << 2,
//        Mouse       = 1 << 3,
//        MouseButton = 1 << 4,
//    };

    void addCallback(const Type& type);
    void callEvent(const Type& type);
    void process();

}