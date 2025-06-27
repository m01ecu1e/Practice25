#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <chrono>

struct SortResult {
    long swapCount;
    double durationSec;
    bool success;
};

SortResult sortAndMeasureHeapsort(std::vector<int>& arr);

long heapsort(std::vector<int>& arr);
void heapify(std::vector<int>& arr, int n, int i, long& swapCount);

#endif