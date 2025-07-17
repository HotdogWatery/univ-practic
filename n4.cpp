#include <iostream>

using namespace std;

int main() {
    int N;
    cout << "Введите натуральное число N: ";
    cin >> N;
    
    int count = 0;
    
    cout << "Трехзначные числа с суммой цифр равной " << N << ":" << endl;
    
    for (int num = 100; num <= 999; num++) {
        int sum = 0;
        int temp = num;
        
        while (temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == N) {
            cout << num << " ";
            count++;
        }
    }
    
    cout << endl << "Количество таких чисел: " << count << endl;
    
    return 0;
}