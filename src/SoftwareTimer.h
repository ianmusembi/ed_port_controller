// -------- SoftwareTimer.h --------
#pragma once
#include <chrono>


class SoftwareTimer {
public:
void start(int durationMs) {
active = true;
expiry = std::chrono::steady_clock::now() + std::chrono::milliseconds(durationMs);
}


bool expired() {
if (active && std::chrono::steady_clock::now() >= expiry) {
active = false;
return true;
}
return false;
}


private:
bool active{false};
std::chrono::steady_clock::time_point expiry;
};