#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>


std::vector<int> generateRandomArray(int size);
std::vector<int> generateBoundedArray(int size, int min = -1000, int max = 1000);
std::vector<int> generateManualArray(int size);

#endif