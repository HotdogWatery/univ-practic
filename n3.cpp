#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateF(double x, double y) {
    if (x < 0 && y < 0) {
        return x * x + y * y;
    } else if (x > 0 && y > 0) {
        return sqrt(x + y);
    } else {
        return sqrt(x * x + y * y);
    }
}

int main() {
    const double start = 0.0;
    const double end = 2.5;
    const double step = 0.5;

    cout << "y\\x |";
    for (double x = start; x <= end + 1e-6; x += step) {
        cout << setw(8) << fixed << setprecision(1) << x;
    }
    cout << endl;

    cout << "----+";
    for (double x = start; x <= end + 1e-6; x += step) {
        cout << "--------";
    }
    cout << endl;
    for (double y = start; y <= end + 1e-6; y += step) {
        cout << setw(3) << fixed << setprecision(1) << y << " |";
        
        for (double x = start; x <= end + 1e-6; x += step) {
            double result = calculateF(x, y);
            cout << setw(8) << fixed << setprecision(4) << result;
        }
        cout << endl;
    }
    
    return 0;
}