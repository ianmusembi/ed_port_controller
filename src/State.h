// -------- State.h --------
#pragma once
#include <string>


enum class State {
INIT,
DOWN,
UP,
ERROR,
RECOVERING
};


inline std::string toString(State s) {
switch (s) {
case State::INIT: return "INIT";
case State::DOWN: return "DOWN";
case State::UP: return "UP";
case State::ERROR: return "ERROR";
case State::RECOVERING: return "RECOVERING";
}
return "UNKNOWN";
}