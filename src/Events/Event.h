#pragma once

#include <functional>
#include <vector>
#include <iostream>

#define BIND_FUNC(f)            [this](auto&&... args) -> decltype(auto) { return this->f(std::forward<decltype(args)>(args)...); }
#define BIND_EVENT(e, t, f)     Events::bind<t>(e, BIND_FUNC(f));
#define EVENT_LISTENER(f)       Events::listen(BIND_FUNC(f))

#define EVENT_CLASS(name, type) public:                                                                 \
                                    static EventType getStaticType() { return EventType::type; }        \
                                    EventType getEventType() const override { return getStaticType(); }

enum class EventType
{
    None = 0,
    WindowClose, WindowResize,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

class Event
{
public:
    virtual EventType getEventType() const = 0;
};

namespace Events {

    typedef std::function<void(Event&)> CallbackFunction;

    template <typename T, typename F>
    void bind(Event& event, const F& func)
    {
        if(T::getStaticType() == event.getEventType())
            func(static_cast<T&>(event));
    }

    void listen(CallbackFunction);
    void dispatch(Event&&);
    void process();

}