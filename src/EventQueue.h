// -------- EventQueue.h --------
#pragma once
#include <queue>
#include "Event.h"


class EventQueue {
public:
void push(const Event& e) { queue.push(e); }
bool empty() const { return queue.empty(); }
Event pop() {
    Event e = queue.front();
    queue.pop();
    return e;
}

private:
std::queue<Event> queue;
};