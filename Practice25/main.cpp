#include "UI.h"
#include "Generator.h"
#include "Sorter.h"
#include "IO.h"
#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

void printArray(const vector<int>& arr) {
    if (arr.size() > 20) {
        cout << "Массив слишком большой, выводятся первые 10 и последние 5 элементов:\n";
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

void runConsoleUI() {
    while (true) {
        cout << "\n==== МЕНЮ ТЕСТИРОВАНИЯ ====\n";
        cout << "1. Тест случайного массива\n";
        cout << "2. Тест массива в границах (-1000..1000)\n";
        cout << "3. Тест с ручным вводом\n";
        cout << "4. Выход\n";
        cout << "Выберите вариант: ";

        int choice;
        cin >> choice;

        if (choice == 4) break;

        int size;
        cout << "Введите размер массива: ";
        cin >> size;

        if (size <= 0) {
            cout << "Некорректный размер!\n";
            continue;
        }

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
        default:
            cout << "Неверный выбор!\n";
            continue;
        }

        testSorting(arr, testName);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    
    cout << "=== АВТОМАТИЧЕСКИЕ ТЕСТЫ ===\n";

    
    vector<int> smallArr = { 5, 3, 8, 1, 2 };
    testSorting(smallArr, "Маленький массив (5 элементов)");

    
    vector<int> mediumArr = generateBoundedArray(20);
    testSorting(mediumArr, "Средний массив (20 элементов) в границах");

    
    vector<int> largeArr = generateRandomArray(1000);
    testSorting(largeArr, "Большой массив (1000 элементов)");

    
    runConsoleUI();

    return 0;
}