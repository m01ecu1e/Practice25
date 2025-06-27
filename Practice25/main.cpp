#include "UI.h"
#include "Generator.h"
#include "Sorter.h"
#include "IO.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <limits>
#include <string>
#include <iomanip>

void runConsoleUI() {
    std::vector<int> arr;
    std::string filename;

    while (true) {
        std::cout << "\n==== ГЛАВНОЕ МЕНЮ ====\n";
        std::cout << "1. Сгенерировать массив\n";
        std::cout << "2. Отсортировать существующий массив\n";
        std::cout << "0. Выход\n";

        int choice;
        std::cout << "Выберите вариант (0-2): ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Ошибка ввода. Введите число от 0 до 2.\n";
            continue;
        }

        std::cin.ignore();

        if (choice == 0) break;

        if (choice == 1) {
            int size, min, max;
            std::cout << "Введите размер массива: ";
            std::cin >> size;

            if (std::cin.fail() || size <= 0) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Ошибка: размер должен быть положительным числом.\n";
                continue;
            }

            std::cout << "Введите минимальное значение: ";
            std::cin >> min;
            std::cout << "Введите максимальное значение: ";
            std::cin >> max;

            if (min > max) {
                std::cout << "Ошибка: минимальное значение должно быть меньше или равно максимальному.\n";
                continue;
            }

            std::cin.ignore();

            arr = generateRandomArray(size, min, max);

            std::cout << "Введите название файла для сохранения: ";
            std::getline(std::cin, filename);
            filename = filename + ".csv";
            if (writeArrayToFile(filename, arr)) {
                std::cout << "Массив сохранён в файл " << filename << "\n";
            }
            else {
                std::cout << "Ошибка при сохранении файла!\n";
            }

        }
        else if (choice == 2) {
            std::cout << "Введите название файла для чтения: ";
            std::getline(std::cin, filename);
            if (readArrayFromFile(filename, arr)) {
                std::cout << "Файл успешно прочитан.\n";

                SortResult result = sortAndMeasureHeapsort(arr);
                std::string sortedFilename;

                std::cout << "Введите название файла для сохранения отсортированного массива: ";
                std::getline(std::cin, sortedFilename);
                sortedFilename = sortedFilename + ".csv";
                if (writeArrayToFile(sortedFilename, arr)) {
                    std::cout << "Массив сохранён в файл " << sortedFilename << "\n";
                }
                else {
                    std::cout << "Ошибка при сохранении файла!\n";
                }


                std::cout << "Массив отсортировался за " << std::fixed << std::setprecision(9)
                    << result.durationSec << " секунд, за " << result.swapCount << " операций.\n";

            }
            else {
                std::cout << "Ошибка при чтении файла!\n";
            }

        }
        else {
            std::cout << "Неверный пункт меню.\n";
        }
    }

    std::cout << "Выход из программы.\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    runConsoleUI();

    return 0;
}