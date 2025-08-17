#pragma once
#include <vector>
#include "DataPoint.h"

class HeapPQueue {
public:
    HeapPQueue();
    ~HeapPQueue();

    void enqueue(const DataPoint& value);
    DataPoint dequeue();
    bool isEmpty() const;

private:
    std::vector<DataPoint> heap;

    void bubbleUp(int index);
    void bubbleDown(int index);
};
