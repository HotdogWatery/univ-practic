#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double calculateCylinderVolume(double radius, double height) {
    return M_PI * radius * radius * height;
}


void printVolumes(double heights[], int h_count, double radii[], int r_count) {
    cout << "Результаты вычисления объемов цилиндров:\n";
    cout << fixed << setprecision(2);
    
    for (int i = 0; i < h_count; i++) {
        for (int j = 0; j < r_count; j++) {
            double volume = calculateCylinderVolume(radii[j], heights[i]);
            cout << "Высота: " << heights[i] << " см, Радиус: " << radii[j] 
                 << " см -> Объем: " << volume << " см³\n";
        }
    }
}

int main() {
    double heights[] = {12.0, 13.0, 14.0, 15.0};
    double radii[] = {5.0, 10.0, 15.0, 20.0};
    
    int h_count = sizeof(heights) / sizeof(heights[0]);
    int r_count = sizeof(radii) / sizeof(radii[0]);
    
    printVolumes(heights, h_count, radii, r_count);
    
    return 0;
}