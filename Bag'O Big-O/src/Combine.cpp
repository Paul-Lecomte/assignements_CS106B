
#include "Combine.h"
#include <cassert>
#include <iterator>

namespace {

// TODO: Implement a linear-time merge of two sorted vectors (by weight).
std::vector<DataPoint> mergeSorted(const std::vector<DataPoint>& a,
                                   const std::vector<DataPoint>& b) {
    // Hints:
    // - Do NOT erase() from the front of vectors. Use index/iterator pointers.
    // - Advance the pointer with the smaller weight each step; push_back to result.
    // - Preserve all duplicates; tie-break arbitrarily.
    std::vector<DataPoint> out;
    out.reserve(a.size() + b.size());

    // YOUR CODE HERE

    return out;
}

// Recursively combine runs[lo, hi) into a single sorted vector.
std::vector<DataPoint> combineRange(const std::vector<std::vector<DataPoint>>& runs,
                                    int lo, int hi) {
    assert(0 <= lo && lo <= hi && hi <= (int)runs.size());
    int len = hi - lo;
    if (len == 0) return {};           // empty
    if (len == 1) return runs[lo];     // single run

    int mid = lo + len / 2;
    auto left  = combineRange(runs, lo, mid);
    auto right = combineRange(runs, mid, hi);
    return mergeSorted(left, right);
}

} // namespace

std::vector<DataPoint> combine(const std::vector<std::vector<DataPoint>>& runs) {
    // Edge cases are handled by combineRange.
    return combineRange(runs, 0, (int)runs.size());
}
