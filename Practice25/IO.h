#ifndef IO_H
#define IO_H

#include <vector>
#include <string>


bool readArrayFromFile(const std::string& filename, std::vector<int>& outArray);

bool writeArrayToFile(const std::string& filename, const std::vector<int>& arr);

bool writeSortReport(const std::string& reportFilename,
    const std::string& originalFilename,
    int size,
    double durationSec,
    long swapCount,
    const std::string& dataType);

bool fileExists(const std::string& filename);

bool makeOutputFilenames(const std::string& inputFilename,
    std::string& sortedFilename,
    std::string& reportFilename);

bool isSortedAscending(const std::vector<int>& arr);
bool isSortedDescending(const std::vector<int>& arr);

#endif 