// -------- EventQueue.h --------
#pragma once
#include <queue>
#include "Event.h"


class EventQueue {
    public:
        void push(const Event& e) { queue.push(e); }
        bool empty() const { return queue.empty(); }

        bool pop(Event& out) {
            if (queue.empty()) return false;
            out = queue.front();
            queue.pop();
            return true;
        }

    private:
        std::queue<Event> queue;
};