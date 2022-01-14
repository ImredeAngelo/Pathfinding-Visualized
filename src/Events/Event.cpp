#include <vector>
#include "Event.h"

static std::vector<Events::Event> events;


void Events::addCallback(const Events::Type &type)
{
    // todo: register callbacks
}

void Events::callEvent(const Events::Event &event)
{
    events.emplace_back(event);
}

void Events::process()
{
    while(!events.empty())
    {
        const Event& e = events.front();
        events.pop_back();

        // call all callbacks registered under type
    }
}
