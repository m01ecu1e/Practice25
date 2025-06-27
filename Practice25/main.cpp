#include "UI.h"
#include "Generator.h"
#include "Sorter.h"
#include "IO.h"
#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

void runConsoleUI() {
    vector<int> arr;
    string filename;

    while (true) {
        cout << "\n==== ГЛАВНОЕ МЕНЮ ====\n";
        cout << "1. Сгенерировать массив\n";
        cout << "2. Отсортировать существующий массив\n";
        cout << "0. Выход\n";

        int choice;
        cout << "Выберите вариант (0-2): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ошибка ввода. Введите число от 0 до 2.\n";
            continue;
        }

        cin.ignore();

        if (choice == 0) break;

        if (choice == 1) {
            int size;
            cout << "Введите размер массива: ";
            cin >> size;

            if (cin.fail() || size <= 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Ошибка: размер должен быть положительным числом.\n";
                continue;
            }

            cin.ignore();

            arr = generateRandomArray(size);

            cout << "Введите название файла для сохранения: ";
            getline(cin, filename);
            if (writeArrayToFile(filename, arr)) {
                cout << "Массив сохранён в файл " << filename << "\n";
            }
            else {
                cout << "Ошибка при сохранении файла!\n";
            }

        }
        else if (choice == 2) {
            cout << "Введите название файла для чтения: ";
            getline(cin, filename);
            if (readArrayFromFile(filename, arr)) {
                cout << "Файл успешно прочитан.\n";

                SortResult result = sortAndMeasureHeapsort(arr);
                string sortedFilename = filename + "_sorted";

                if (writeArrayToFile(sortedFilename, arr)) {
                    cout << "Отсортированный массив сохранён в файл " << sortedFilename << "\n";
                }
                else {
                    cout << "Ошибка при сохранении отсортированного файла!\n";
                }

                cout << "Массив отсортировался за " << result.durationSec
                    << " секунд, за " << result.swapCount << " операций.\n";

            }
            else {
                cout << "Ошибка при чтении файла!\n";
            }

        }
        else {
            cout << "Неверный пункт меню.\n";
        }
    }

    cout << "Выход из программы.\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    runConsoleUI();
    return 0;
}