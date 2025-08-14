
#include <cassert>
#include <algorithm>
#include <random>
#include <vector>
#include <iostream>
#include "Combine.h"
#include "../include/Generators.h"

// A slow reference used for testing: flatten then sort by weight.
static std::vector<DataPoint>
slowBaseline(const std::vector<std::vector<DataPoint>>& runs) {
    std::vector<DataPoint> flat;
    size_t total = 0;
    for (auto& v : runs) total += v.size();
    flat.reserve(total);
    for (auto& v : runs) flat.insert(flat.end(), v.begin(), v.end());
    std::sort(flat.begin(), flat.end(), [](const DataPoint& a, const DataPoint& b){
        if (a.weight != b.weight) return a.weight < b.weight;
        return a.name < b.name;
    });
    return flat;
}

static void requireEqualByWeight(const std::vector<DataPoint>& a,
                                 const std::vector<DataPoint>& b) {
    if (a.size() != b.size()) {
        std::cerr << "Size mismatch! a.size()=" << a.size()
                  << " b.size()=" << b.size() << "\n";
        std::cerr << "Output a:\n";
        for (auto& dp : a) std::cerr << dp << " ";
        std::cerr << "\nExpected b:\n";
        for (auto& dp : b) std::cerr << dp << " ";
        std::cerr << "\n";
    }
    assert(a.size() == b.size());
    for (size_t i = 0; i < a.size(); ++i) {
        assert(a[i].weight == b[i].weight);
    }
}

void runTests() {
    // Empty input
    {
        std::vector<std::vector<DataPoint>> runs;
        auto out = combine(runs);
        assert(out.empty());
    }
    // Single run
    {
        std::vector<std::vector<DataPoint>> runs = {
            { {"a",1}, {"b",3}, {"c",3}, {"d",9} }
        };
        auto out = combine(runs);
        assert(out.size() == runs[0].size());
        requireEqualByWeight(out, runs[0]);
    }
    // Two runs different sizes, with duplicates
    {
        std::vector<DataPoint> A = { {"a",1}, {"b",4}, {"c",7} };
        std::vector<DataPoint> B = { {"x",2}, {"y",4}, {"z",10}, {"w",10} };
        std::vector<std::vector<DataPoint>> runs = {A, B};
        auto out = combine(runs);
        auto ref = slowBaseline(runs);
        requireEqualByWeight(out, ref);
    }
    // Fuzz tests
    {
        std::mt19937 rng(1337);
        for (int t = 0; t < 100; ++t) {
            int k = 1 + (rng() % 7);
            int n = 1 + (rng() % 2000);
            auto runs = makeKRuns(rng, k, n);
            auto out = combine(runs);
            auto ref = slowBaseline(runs);
            requireEqualByWeight(out, ref);
        }
    }
    std::cout << "[OK] All tests passed.\n";
}
