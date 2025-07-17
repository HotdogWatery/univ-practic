#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateAverage(const vector<int>& arr) {
    double sum = 0.0;
    for (int val : arr) {
        sum += val;
    }
    return sum / arr.size();
}

int findClosestRow(const vector<vector<int>>& matrix, const vector<double>& columnAverages) {
    int closestRow = 0;
    double minDiff = numeric_limits<double>::max();

    for (size_t i = 0; i < matrix.size(); ++i) {
        double totalDiff = 0.0;
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            totalDiff += abs(matrix[i][j] - columnAverages[j]);
        }

        if (totalDiff < minDiff) {
            minDiff = totalDiff;
            closestRow = i;
        }
    }

    return closestRow;
}

void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << setw(8) << fixed << setprecision(2) << val;
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    
    cout << "Введите размеры матрицы (n m): ";
    cin >> n >> m;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<double> columnAverages(m);
    for (int j = 0; j < m; ++j) {
        vector<int> column;
        for (int i = 0; i < n; ++i) {
            column.push_back(matrix[i][j]);
        }
        columnAverages[j] = calculateAverage(column);
    }

    vector<vector<double>> extendedMatrix(matrix.begin(), matrix.end());
    extendedMatrix.push_back(columnAverages);

    int closestRow = findClosestRow(matrix, columnAverages);

    cout << "\nИсходная матрица с добавленной строкой средних:" << endl;
    printMatrix(extendedMatrix);

    cout << "\nСредние значения столбцов:" << endl;
    for (size_t j = 0; j < columnAverages.size(); ++j) {
        cout << "Столбец " << j + 1 << ": " << fixed << setprecision(2) << columnAverages[j] << endl;
    }

    cout << "\nСтрока с наиболее близкими к среднему значениями: " << closestRow + 1 << endl;
    cout << "Элементы этой строки:" << endl;
    for (int val : matrix[closestRow]) {
        cout << setw(5) << val;
    }
    cout << endl;

    return 0;
}