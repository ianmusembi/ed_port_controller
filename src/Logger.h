#pragma once
#include <iostream>
#include <chrono>
#include <string>


static auto programStart = std::chrono::steady_clock::now();


inline long long timestampMs() {
auto now = std::chrono::steady_clock::now();
return std::chrono::duration_cast<std::chrono::milliseconds>(now - programStart).count();
}


inline void log(const std::string& msg) {
std::cout << "[" << timestampMs() << " ms] " << msg << std::endl;
}