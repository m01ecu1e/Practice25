#include "UI.h"
#include "Generator.h"
#include "Sorter.h"
#include "IO.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits> 
using namespace std;

void printArray(const vector<int>& arr) {
    if (arr.size() > 20) {
        cout << "Массив  большой, выводятся первые 10 и последние 5 элементов:\n";
        for (int i = 0; i < 10; ++i) cout << arr[i] << " ";
        cout << "... ";
        for (size_t i = arr.size() - 5; i < arr.size(); ++i) cout << arr[i] << " ";
    }
    else {
        for (int num : arr) cout << num << " ";
    }
    cout << "\n";
}

void testSorting(const vector<int>& original, const string& testName) {
    vector<int> arr = original;
    cout << "\n=== Тест: " << testName << " ===\n";
    cout << "Исходный массив (" << arr.size() << " элементов):\n";
    printArray(arr);

    SortResult result = sortAndMeasureHeapsort(arr);

    cout << "Отсортированный массив:\n";
    printArray(arr);
    cout << "Результаты:\n";
    cout << "  Время сортировки: " << fixed << setprecision(6) << result.durationSec << " сек\n";
    cout << "  Количество обменов: " << result.swapCount << "\n";
    cout << "  Успешно: " << (result.success ? "Да" : "Нет") << "\n";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getIntInput(const string& prompt, int minValue = INT_MIN, int maxValue = INT_MAX) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < minValue || value > maxValue) {
            cout << "Ошибка, введите целое число";
            if (minValue != INT_MIN || maxValue != INT_MAX) {
                cout << " в диапазоне [" << minValue << ".." << maxValue << "]";
            }
            cout << ".\n";
            clearInputBuffer();
        }
        else {
            clearInputBuffer();
            return value;
        }
    }
}

void runConsoleUI() {
    while (true) {
        cout << "\n==== МЕНЮ ТЕСТИРОВАНИЯ ====\n";
        cout << "1. Случайный массив\n";
        cout << "2. Массив в границах (-1000..1000)\n";
        cout << "3. Массив с ручным вводом\n";
        cout << "4. Выход\n";

        int choice = getIntInput("Выберите вариант: ", 1, 4);

        if (choice == 4) break;

        int size = getIntInput("Введите размер массива: ", 1);

        vector<int> arr;
        string testName;

        switch (choice) {
        case 1:
            arr = generateRandomArray(size);
            testName = "Случайный массив";
            break;
        case 2:
            arr = generateBoundedArray(size);
            testName = "Массив в границах (-1000..1000)";
            break;
        case 3:
            arr = generateManualArray(size);
            testName = "Массив с ручным вводом";
            break;
        }

        testSorting(arr, testName);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    runConsoleUI();
    return 0;
}