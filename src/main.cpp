// -------- main.cpp --------
#include <thread>
#include <random>
#include "PortController.h"


int main() {
    EventQueue queue;
    PortController controller(queue);


    controller.init();


    std::default_random_engine rng;
    std::uniform_int_distribution<int> faultChance(0, 9);


    while (true) {
        controller.processTimers();

        Event e;
        if (!queue.pop(e)) {    
            controller.handleEvent(e);
        }


        static bool linkUpSent = false;
        if (controller.getState() == State::DOWN && !linkUpSent) {
            queue.push({EventType::LINK_UP});
            linkUpSent = true;
        }
        if (controller.getState() != State::DOWN) {
            linkUpSent = false;
        }


        if (controller.getState() == State::UP && faultChance(rng) == 0) {
            log("FAULT detected");
            queue.push({EventType::FAULT_DETECTED});
        }


        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}