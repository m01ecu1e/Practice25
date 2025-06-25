#include "Sorter.h"
#include <chrono>

void heapify(std::vector<int>& arr, int n, int i, long& swapCount) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        swapCount++;
        heapify(arr, n, largest, swapCount);
    }
}

long heapsort(std::vector<int>& arr) {
    long swapCount = 0;
    int n = arr.size();

    
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, swapCount);
    }

    
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        swapCount++;
        heapify(arr, i, 0, swapCount);
    }

    return swapCount;
}

SortResult sortAndMeasureHeapsort(std::vector<int>& arr) {
    SortResult result;
    auto start = std::chrono::high_resolution_clock::now();

    result.swapCount = heapsort(arr);

    auto end = std::chrono::high_resolution_clock::now();
    result.durationSec = std::chrono::duration<double>(end - start).count();
    result.success = true;

    return result;
}