// -------- PortController.h --------
#pragma once
#include "EventQueue.h"
#include "SoftwareTimer.h"
#include "State.h"
#include "Logger.h"


class PortController {
    public:
        explicit PortController(EventQueue& q);
        void init();
        void handleEvent(const Event& e);
        void processTimers();
        State getState() const;


    private:
        void transition(State newState);


    State state{State::INIT};
    EventQueue& eventQueue;
    SoftwareTimer recoveryTimer;
};