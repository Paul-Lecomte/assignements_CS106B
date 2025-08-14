
#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include "DataPoint.h"

inline std::vector<DataPoint> makeSortedRun(std::mt19937& rng, int len, int minW=0, int maxW=1'000'000) {
    std::uniform_int_distribution<int> dist(minW, maxW);
    std::vector<DataPoint> v;
    v.reserve(len);
    for (int i = 0; i < len; ++i) v.push_back(DataPoint{std::to_string(i), dist(rng)});
    std::sort(v.begin(), v.end(), [](const DataPoint& a, const DataPoint& b){
        if (a.weight != b.weight) return a.weight < b.weight;
        return a.name < b.name;
    });
    return v;
}

// Build k sorted runs whose *total* length ~= n. Sizes are varied a bit.
inline std::vector<std::vector<DataPoint>> makeKRuns(std::mt19937& rng, int k, int n) {
    std::vector<std::vector<DataPoint>> out;
    out.reserve(std::max(0, k));
    if (k <= 0) return out;
    if (n <= 0) { out.assign(k, {}); return out; }

    // Distribute n approximately evenly across k buckets, with jitter.
    std::uniform_int_distribution<int> jitter(0, 7);
    int base = n / k;
    int rem = n % k;
    for (int i = 0; i < k; ++i) {
        int len = base + (i < rem ? 1 : 0) + jitter(rng);
        len = std::max(0, len);
        auto run = makeSortedRun(rng, len);
        // Tag names so duplicates across runs are distinct
        for (auto& d : run) d.name = std::to_string(i) + ":" + d.name;
        out.push_back(std::move(run));
    }
    return out;
}
