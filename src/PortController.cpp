// -------- PortController.cpp --------
#include "PortController.h"


PortController::PortController(EventQueue& q)
: eventQueue(q) {
    log("PortController created");
}


void PortController::init() {
    transition(State::INIT);
    eventQueue.push({EventType::LINK_DOWN});
}


void PortController::handleEvent(const Event& e) {
    switch (state) {
        case State::INIT:
                transition(State::DOWN);
            break;

        case State::DOWN:
            if (e.type == EventType::LINK_UP)
                transition(State::UP);
            break;

        case State::UP:
            if (e.type == EventType::FAULT_DETECTED)
                transition(State::ERROR);
            break;

        case State::ERROR:
            recoveryTimer.start(2000);
            transition(State::RECOVERING);
            break;

        case State::RECOVERING:
            if (e.type == EventType::RECOVERY_COMPLETE)
                transition(State::DOWN);
            break;

        default:
            log("Ignoring event in current state");
            break;
    }
}


void PortController::processTimers() {
    if (state == State::RECOVERING && recoveryTimer.expired()) {
        eventQueue.push({EventType::RECOVERY_COMPLETE});
    }
}


State PortController::getState() const {
    return state;
}


void PortController::transition(State newState) {
    log("STATE: " + toString(state) + " -> " + toString(newState));
    state = newState;
}