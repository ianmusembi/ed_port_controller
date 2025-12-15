// -------- Event.h --------
#pragma once


enum class EventType {
LINK_UP,
LINK_DOWN,
FAULT_DETECTED,
TIMER_EXPIRED,
RECOVERY_COMPLETE
};


struct Event {
EventType type;
};