#include <iostream>
using namespace std;

int main() {
    double K1, K2, K3;
    int N; 
    
    cout << "Введите количество наборов (N): ";
    cin >> N;
    cout << "Введите стоимость шоколадки (K1 руб.): ";
    cin >> K1;
    cout << "Введите стоимость яблока (K2 руб.): ";
    cin >> K2;
    cout << "Введите стоимость печенья (K3 руб.): ";
    cin >> K3;

    double totalCost = (2 * K1 + 2 * K2 + K3) * N;
    cout << "Общая стоимость покупки: " << totalCost << " руб." << endl;

    return 0;
}
