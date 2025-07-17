#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    char repeat;
    do {
        // Ввод данных
        int K1, K2, X, Y;
        double P1, X1, P2, X2, P3, X3;
        
        cout << "Введите K1 (калории для мыши в день): ";
        cin >> K1;
        cout << "Введите K2 (калории для крысы в день): ";
        cin >> K2;
        cout << "Введите X (количество мышей): ";
        cin >> X;
        cout << "Введите Y (количество крыс): ";
        cin >> Y;
        cout << "Введите P1 (калорийность корма 1 в кг): ";
        cin >> P1;
        cout << "Введите X1 (цена корма 1 за кг): ";
        cin >> X1;
        cout << "Введите P2 (калорийность корма 2 в кг): ";
        cin >> P2;
        cout << "Введите X2 (цена корма 2 за кг): ";
        cin >> X2;
        cout << "Введите P3 (калорийность корма 3 в кг): ";
        cin >> P3;
        cout << "Введите X3 (цена корма 3 за кг): ";
        cin >> X3;

        int totalCalories = K1 * X + K2 * Y;

        double cost1 = (totalCalories / P1) * X1;
        double cost2 = (totalCalories / P2) * X2;
        double cost3 = (totalCalories / P3) * X3;

        double minCost = cost1;
        int bestFood = 1;

        if (cost2 < minCost) {
            minCost = cost2;
            bestFood = 2;
        }

        if (cost3 < minCost) {
            minCost = cost3;
            bestFood = 3;
        }

        cout << "\nСамый дешевый дневной рацион:" << endl;
        cout << "Использовать корм " << bestFood << endl;
        cout << "Стоимость: " << minCost << " руб." << endl;

        cout << "\nХотите выполнить еще один расчет? (y/n): ";
        cin >> repeat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}