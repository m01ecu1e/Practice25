#include "Generator.h"
#include <random>
#include <chrono>

std::vector<int> generateRandomArray(int size, int min, int max) {
    std::vector<int> arr(size);


    std::random_device rd;
    std::mt19937 gen(rd());


    if (min > max) {
        std::swap(min, max);
    }


    std::uniform_int_distribution<int> dist(min, max);


    for (int& num : arr) {
        num = dist(gen);
    }

    return arr;
}