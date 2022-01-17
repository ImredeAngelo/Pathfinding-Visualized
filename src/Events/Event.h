#pragma once

#include <functional>
#include <vector>
#include <iostream>

#define BIND_FUNC(f)        [this](auto&&... args) -> decltype(auto) { return this->f(std::forward<decltype(args)>(args)...); }
#define BIND_EVENT(e, t, f) Events::bind<t>(e, BIND_FUNC(f));
#define EVENT_LISTENER(f)   Events::listen(BIND_FUNC(f))

#define EVENT_TYPE(type)    public:                                                                 \
                                static EventType getStaticType() { return EventType::type; }        \
                                EventType getEventType() const override { return getStaticType(); } \
                            private:

enum class EventType
{
    None = 0,
    WindowClose, WindowResize,
    KeyPress, KeyRelease,
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


// TODO:
//  - Generic events
//  - Buffered events

// Events::listen<EventDataType>(func); // func(EventDataType&);
// Events::dispatch(EventDataType(...));


//template <EventType T>
//class TEvent
//{
//public:
//    static EventType getStaticType() { return T; }
//    virtual void dispatch() const = 0;
//};
//
//class TestEvent final : public TEvent<EventType::MouseMoved>
//{
//public:
//    TestEvent() = default;
//
//    void dispatch() const override
//    {
//
//    }
//};

//namespace Events {
//
//    static std::vector<const std::function<void(Event&)>&> e;
//
//    struct EventPair
//    {
//
//
//        static
//    };
//
//    template <EventType T>
//    void listen(const std::function<void(TEvent<T>&)>& func)
//    {
//        e.push_back(func);
//    }
//
//    template <EventType T>
//    void dispatch(TEvent<T> e)
//    {
//
//    }
//
//}