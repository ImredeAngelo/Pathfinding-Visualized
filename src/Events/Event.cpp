#include "Event.h"
#include <deque>

static auto listeners = std::vector<Events::CallbackFunction>();
static auto q = std::vector<Event>();

void Events::listen(Events::CallbackFunction func)
{
    listeners.emplace_back(func);
}

void Events::dispatch(Event&& event)
{
    for(auto const& f : listeners)
        f(event);
}

void Events::process()
{
    while(!q.empty())
    {
        Event& event = q.back();
        q.pop_back();

        for(auto const& f : listeners)
            f(event);
    }
}