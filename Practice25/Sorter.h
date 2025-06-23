#ifndef SORTER_H
#define SORTER_H

#include <vector>

struct SortResult {
    long swapCount;
    double durationSec;
};

SortResult sortAndMeasureHeapsort(std::vector<int>& arr);

long heapsort(std::vector<int>& arr);

#endif