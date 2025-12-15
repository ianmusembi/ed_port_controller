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


        if (!queue.empty()) {
            Event e = queue.pop();
            controller.handleEvent(e);
        }


        if (controller.getState() == State::DOWN) {
            queue.push({EventType::LINK_UP});
        }


        if (controller.getState() == State::UP && faultChance(rng) == 0) {
            log("FAULT detected");
            queue.push({EventType::FAULT_DETECTED});
        }


        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}