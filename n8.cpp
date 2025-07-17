#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateWeights(vector<int>& weights, int count) {
    srand(time(0));
    for (int i = 0; i < count; i++) {
        weights.push_back(70 + rand() % 81);
    }
}

void rotateRight(vector<int>& weights) {
    if (weights.empty()) return;
    
    int last = weights.back();
    for (int i = weights.size() - 1; i > 0; i--) {
        weights[i] = weights[i - 1];
    }
    weights[0] = last;
}

void printWeights(const vector<int>& weights) {
    cout << "Текущее расположение весов: [";
    for (size_t i = 0; i < weights.size(); i++) {
        cout << weights[i];
        if (i < weights.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}
int main() {
    int n, k;
    
    cout << "Введите количество толстяков: ";
    cin >> n;
    
    vector<int> weights;
    
    generateWeights(weights, n);
    
    cout << "Введите количество часов K: ";
    cin >> k;
    

    cout << "\nНачальное расположение:" << endl;
    printWeights(weights);
    
    for (int hour = 1; hour <= k; hour++) {
        rotateRight(weights);
        cout << "После " << hour << " часа:" << endl;
        printWeights(weights);
    }
    
    return 0;
}
