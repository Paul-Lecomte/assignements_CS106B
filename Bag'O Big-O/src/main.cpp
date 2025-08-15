// Project: Bag'O Big-O
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <cmath>
#include "Combine.h"
#include "../include/Generators.h"
#include "../include/Timer.h"

void runTests();

static void timeHarness(int maxPowK = 6, int maxPowN = 18) {
    // k takes values 1, 4, 16, ..., 4^m where m = maxPowK
    // n takes values 2^10 .. 2^maxPowN approximately per k
    std::mt19937 rng(42);
    std::cout << "k,n,ms\n";
    for (int pk = 0; pk <= maxPowK; ++pk) {
        int k = (int)std::pow(4.0, pk); // 1,4,16,...
        for (int pn = 10; pn <= maxPowN; ++pn) {
            int n = 1 << pn;
            auto runs = makeKRuns(rng, k, n);
            Timer timer;
            timer.start();
            auto out = combine(runs);
            double ms = timer.stopMs();
            // Touch output to avoid optimizing away
            if (!out.empty() && (out.front().weight > out.back().weight)) {
                std::cerr << "sanity fail\n";
            }
            std::cout << k << "," << n << "," << ms << "\n";
        }
    }
}

int main(int argc, char** argv) {
    if (argc >= 2) {
        std::string arg = argv[1];
        if (arg == std::string("--time")) {
            timeHarness();
            return 0;
        }
        if (arg == std::string("--bench")) {
            int pk = 6, pn = 18;
            if (argc >= 3) pk = std::stoi(argv[2]);
            if (argc >= 4) pn = std::stoi(argv[3]);
            timeHarness(pk, pn);
            return 0;
        }
    }
    runTests();
    return 0;
}
