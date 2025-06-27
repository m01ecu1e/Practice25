#ifndef IO_H
#define IO_H

#include <vector>
#include <string>
#include <fstream>

bool readArrayFromFile(const std::string& filename, std::vector<int>& outArray);

bool writeArrayToFile(const std::string& filename, const std::vector<int>& arr);


#endif 