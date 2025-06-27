#include "Generator.h"
#include <random>
#include <iostream>
#include <limits>

std::vector<int> generateRandomArray(int size) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int& num : arr) {
        num = gen();
    }

    return arr;
}



