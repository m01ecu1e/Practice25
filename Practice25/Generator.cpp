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

std::vector<int> generateBoundedArray(int size, int min, int max) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);

    for (int& num : arr) {
        num = distr(gen);
    }

    return arr;
}

std::vector<int> generateManualArray(int size) {
    std::vector<int> arr(size);
    std::cout << "¬ведите " << size << " элементов массива:\n";

    for (int i = 0; i < size; ++i) {
        std::cout << "Ёлемент " << i + 1 << ": ";
        while (!(std::cin >> arr[i])) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ќшибка, введите целое число: ";
        }
    }

    return arr;
}

std::vector<int> generateArray(int size, ArrayType type) {
    switch (type) {
    case ArrayType::RANDOM:
        return generateRandomArray(size);
    case ArrayType::BOUNDED:
        return generateBoundedArray(size);
    case ArrayType::MANUAL:
        return generateManualArray(size);
    default:
        return generateRandomArray(size);
    }
}