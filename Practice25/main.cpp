#include "UI.h"
#include "Generator.h"
#include "Sorter.h"
#include "IO.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <limits>
#include <string>

using namespace std;

// НАДО:
// Ввод диапазона генерации чисел для generateRandomArray(size);
// Будет generateRandomArray(size, min, max);
//
// Желательно: 
// убрать using namespace std;
// и писать std::cout / std::cin
// 
// 
// 
// 
// ОПЦИОНАЛЬНО:
// 
// Сделать форматирование вывода секунд, чтобы было не 2.12e-10, а 0.000000002 секунд, типа того
//
// ОПЦИОНАЛЬНО: сделать чтобы не надо было вводить .csv при открытия файла

void runConsoleUI() {
    vector<int> arr;
    string filename;

    while (true) {
        std::cout << "\n==== ГЛАВНОЕ МЕНЮ ====\n";
        std::cout << "1. Сгенерировать массив\n";
        std::cout << "2. Отсортировать существующий массив\n";
        std::cout << "0. Выход\n";

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
            filename = filename + ".csv";
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
                string sortedFilename;

                cout << "Введите название файла для сохранения отсортированного массива: ";
                getline(cin, sortedFilename);
                sortedFilename = sortedFilename + ".csv";
                if (writeArrayToFile(sortedFilename, arr)) {
                    cout << "Массив сохранён в файл " << sortedFilename << "\n";
                }
                else {
                    cout << "Ошибка при сохранении файла!\n";
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
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    runConsoleUI();

    return 0;
}