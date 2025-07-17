#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

double calculateAverage(const vector<double>& arr) {
    double sum = 0.0;
    for (double num : arr) {
        sum += num;
    }
    return sum / arr.size();
}

int findClosestRow(const vector<vector<double>>& matrix, const vector<double>& columnAverages) {
    int closestRow = 0;
    double minDifference = numeric_limits<double>::max();

    for (int i = 0; i < matrix.size(); ++i) {
        double rowDifference = 0.0;
        for (int j = 0; j < matrix[i].size(); ++j) {
            rowDifference += abs(matrix[i][j] - columnAverages[j]);
        }

        if (rowDifference < minDifference) {
            minDifference = rowDifference;
            closestRow = i;
        }
    }

    return closestRow;
}

int main() {
    int n, m;
    cout << "Введите количество строк (n) и столбцов (m) матрицы: ";
    cin >> n >> m;

    vector<vector<double>> matrix(n + 1, vector<double>(m));

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<double> columnAverages(m);
    for (int j = 0; j < m; ++j) {
        vector<double> column(n);
        for (int i = 0; i < n; ++i) {
            column[i] = matrix[i][j];
        }
        columnAverages[j] = calculateAverage(column);
        matrix[n][j] = columnAverages[j];
    }

    cout << "\nМатрица с добавленной строкой средних значений:" << endl;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int closestRow = findClosestRow(matrix, columnAverages);
    cout << "\nСтрока, наиболее близкая к средним значениям: " << closestRow + 1 << endl;

    return 0;
}
