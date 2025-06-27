#include "IO.h"
#include <sstream>
#include <iomanip>

bool readArrayFromFile(const std::string& filename, std::vector<int>& outArray) {
    std::ifstream file(filename);
    if (!file) return false;

    outArray.clear();
    std::string value;
    while (std::getline(file, value, ',')) {
        try {
            outArray.push_back(std::stoi(value));
        }
        catch (...) {
            return false;
        }
    }

    return true;
}

bool writeArrayToFile(const std::string& filename, const std::vector<int>& arr) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    for (size_t i = 0; i < arr.size(); ++i) {
        file << arr[i];
        if (i != arr.size() - 1) {
            file << ",";
        }
    }

    file.close();
    return true;
}

bool writeSortReport(const std::string& reportFilename,
    const std::string& originalFilename,
    int size,
    double durationSec,
    long swapCount) {
    std::ofstream file(reportFilename);
    if (!file.is_open()) {
        return false;
    }

    file << "Массив " << originalFilename << " размером " << size
        << " отсортирован за " << std::fixed << std::setprecision(6) << durationSec
        << " секунд за " << swapCount << " операций\n";

    file.close();
    return true;
}