#include <iostream>
using namespace std;

int main() {
    double K1, K2, K3;
    cout << "Введите стоимость одного подарка (K1 руб.): ";
    cin >> K1;
    cout << "Введите стоимость одного яблока (K2 руб.): ";
    cin >> K2;
    cout << "Введите стоимость коробки печенья (K3 руб.): ";
    cin >> K3;

    double totalCost = 2 * K1 + 2 * K2 + K3;
    cout << "Общая стоимость покупки: " << totalCost << " руб." << endl;

    return 0;
}