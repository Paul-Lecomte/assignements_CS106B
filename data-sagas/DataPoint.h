#pragma once
#include <string>
#include <iostream>

struct DataPoint {
    std::string name;
    int weight;

    DataPoint(const std::string& n = "", int w = 0) : name(n), weight(w) {}
};

inline std::ostream& operator<<(std::ostream& out, const DataPoint& dp) {
    out << "(" << dp.name << ", " << dp.weight << ")";
    return out;
}