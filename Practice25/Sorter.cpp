#include "Sorter.h"
#include <chrono>

void heapify(std::vector<int>& arr, int n, int i, long& swapCount) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Заменяем if на switch-case
    switch (left < n && arr[left] > arr[largest]) {
    case true:
        largest = left;
        break;
    default:
        break;
    }

    switch (right < n && arr[right] > arr[largest]) {
    case true:
        largest = right;
        break;
    default:
        break;
    }

    switch (largest != i) {
    case true:
        std::swap(arr[i], arr[largest]);
        swapCount++;
        heapify(arr, n, largest, swapCount);
        break;
    default:
        break;
    }
}

long heapsort(std::vector<int>& arr) {
    long swapCount = 0;
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, swapCount);
    }

    // Extract elements from heap
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