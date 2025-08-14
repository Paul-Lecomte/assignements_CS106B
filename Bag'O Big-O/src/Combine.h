
#pragma once
#include <vector>
#include "../include/DataPoint.h"

// Combine k sorted sequences into one sorted sequence in O(n log k)
// where n is the total number of elements and k is the number of sequences.
std::vector<DataPoint> combine(const std::vector<std::vector<DataPoint>>& runs);
