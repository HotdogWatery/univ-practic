#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    double C0, Cn;
    
    cout << "Введите начальную температуру в градусах Цельсия (C0): ";
    cin >> C0;
    
    cout << "Введите конечную температуру в градусах Цельсия (Cn): ";
    cin >> Cn;
    

    if (C0 > Cn) {
        cout << "Ошибка: начальное значение должно быть меньше конечного." << endl;
        return 1;
    }
    
    cout << "\nТаблица перевода температур:\n";
    cout << " Цельсий (C) | Фаренгейт (F)\n";
    
    cout << fixed << setprecision(1);
    
    for (double C = C0; C <= Cn; C += 1.0) {
        double F = 1.8 * C + 32.0;
        cout << setw(10) << C << "  |" << setw(12) << F << endl;
    }
    
    return 0;
}