
#pragma once
#include <string>
#include <ostream>

struct DataPoint {
    std::string name; // label
    int weight;       // sort key

    // Optional: pretty-print
    friend std::ostream& operator<<(std::ostream& os, const DataPoint& d) {
        return (os << "{" << d.name << "," << d.weight << "}");
    }
};

// Compare by weight, stable tie-breaking is not required by the assignment.
inline bool operator<(const DataPoint& a, const DataPoint& b) {
    return a.weight < b.weight;
}
