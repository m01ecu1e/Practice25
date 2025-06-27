#include "UI.h"
#include "Generator.h"
#include "Sorter.h"
#include "IO.h"
#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getIntInput(const string& prompt, int min = INT_MIN, int max = INT_MAX) {
    int value;
    while (cout << prompt && (!(cin >> value) || value < min || value > max)) {
        cout << "Ошибка, введите целое число";
        if (min != INT_MIN || max != INT_MAX) cout << " [" << min << ".." << max << "]";
        cout << ".\n";
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

void runConsoleUI() {
    vector<int> arr;
    string filename;

    while (true) {
        cout << "\n==== ГЛАВНОЕ МЕНЮ ====\n"
            << "1. Сгенерировать массив\n"
            << "2. Отсортировать существующий массив\n"
            << "0. Выход\n";

        int choice = getIntInput("Выберите вариант (0-2): ", 0, 2);

        switch (choice) {
        case 0:
            return; // Выход из программы

        case 1: {
            int size = getIntInput("Введите размер массива: ", 1);
            arr = generateRandomArray(size);

            cout << "Введите название файла для сохранения: ";
            getline(cin, filename);

            if (writeArrayToFile(filename, arr)) {
                cout << "Массив сохранен в файл " << filename << "\n";
            }
            else {
                cout << "Ошибка при сохранении файла!\n";
            }
            break;
        }

        case 2: {
            cout << "Введите название файла для чтения: ";
            getline(cin, filename);

            if (readArrayFromFile(filename, arr)) {
                cout << "Файл успешно прочитан\n";

                SortResult result = sortAndMeasureHeapsort(arr);
                string sortedFilename = filename + "_sorted";

                if (writeArrayToFile(sortedFilename, arr)) {
                    cout << "Отсортированный массив сохранен в файл " << sortedFilename << "\n";
                }
                else {
                    cout << "Ошибка при сохранении отсортированного файла!\n";
                }

                cout << "Массив отсортировался за " << result.durationSec
                    << " секунд, за " << result.swapCount << " операций\n";
            }
            else {
                cout << "Ошибка при чтении файла!\n";
            }
            break;
        }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    runConsoleUI();
    return 0;
}