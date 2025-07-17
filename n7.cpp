#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// ------------------------------- 1 -------------------------------
int isArithmeticProgression(int* arr, int size) {
    if (size < 2) return 0;
    
    int diff = arr[1] - arr[0];
    bool isIncreasing = true;
    bool isDecreasing = true;
    
    for (int i = 1; i < size - 1; i++) {
        int currentDiff = arr[i+1] - arr[i];
        if (currentDiff != diff) return 0;
        if (currentDiff <= 0) isIncreasing = false;
        if (currentDiff >= 0) isDecreasing = false;
    }
    
    if (isIncreasing) return 1;
    if (isDecreasing) return -1;
    return 0;
}

// ------------------------------- 2 -------------------------------
void inputArray(int* arr, int size) {
    cout << "Введите " << size << " элементов массива:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(int* arr, int size) {
    cout << "Массив: [";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]\n";
}

int removeZeros(int* arr, int size) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[newSize++] = arr[i];
        }
    }
    return newSize;
}

void rearrangeArray(int* arr, int size) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        if (arr[left] > 0) {
            left++;
        } else if (arr[right] <= 0) {
            right--;
        } else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

// ------------------------------- 3 -------------------------------
void generateRandomArray(int* arr, int size, int minVal, int maxVal) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

void generateArithmeticProgression(int* arr, int size, int first, int diff) {
    for (int i = 0; i < size; i++) {
        arr[i] = first + i * diff;
    }
}
// ------------------------------- main -------------------------------
int main() {
    const int SIZE = 10;
    int arr[SIZE];
    
    generateArithmeticProgression(arr, SIZE, 2, 3);
    printArray(arr, SIZE);
    int result = isArithmeticProgression(arr, SIZE);
    cout << "Результат проверки прогрессии: " << result << "\n\n";
    
    inputArray(arr, SIZE);
    printArray(arr, SIZE);
    
    int newSize = removeZeros(arr, SIZE);
    cout << "После удаления нулей: ";
    printArray(arr, newSize);
    
    rearrangeArray(arr, newSize);
    cout << "После перестановки: ";
    printArray(arr, newSize);
    
    generateRandomArray(arr, SIZE, -10, 10);
    cout << "\nСлучайный массив: ";
    printArray(arr, SIZE);
    
    generateArithmeticProgression(arr, SIZE, 5, -2);
    cout << "Арифметическая прогрессия: ";
    printArray(arr, SIZE);
    
    return 0;
}