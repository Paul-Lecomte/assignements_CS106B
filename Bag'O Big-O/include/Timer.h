
#pragma once
#include <chrono>

class Timer {
public:
    using clock = std::chrono::steady_clock;
    using ms = std::chrono::duration<double, std::milli>;

    void start() { t0 = clock::now(); }
    double stopMs() const { return ms(clock::now() - t0).count(); }

private:
    clock::time_point t0 = clock::now();
};
