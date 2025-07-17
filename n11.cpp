#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Performance {
    string name;
    int showCount;
    int childTickets;
    double childPrice;
    int adultTickets;
    double adultPrice;
};

vector<Performance> performances;

void loadDataFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Файл не найден. Будет создан новый." << endl;
        return;
    }

    Performance p;
    while (file >> p.name >> p.showCount >> p.childTickets >> p.childPrice 
              >> p.adultTickets >> p.adultPrice) {
        performances.push_back(p);
    }
    file.close();
}

void saveDataToFile(const string& filename) {
    ofstream file(filename);
    for (const auto& p : performances) {
        file << p.name << " " << p.showCount << " " << p.childTickets << " "
             << p.childPrice << " " << p.adultTickets << " " << p.adultPrice << endl;
    }
    file.close();
}

void updatePerformanceData() {
    Performance newData;
    cout << "Введите название спектакля: ";
    cin >> newData.name;
    cout << "Введите количество показов: ";
    cin >> newData.showCount;
    cout << "Введите количество проданных детских билетов: ";
    cin >> newData.childTickets;
    cout << "Введите цену детского билета: ";
    cin >> newData.childPrice;
    cout << "Введите количество проданных взрослых билетов: ";
    cin >> newData.adultTickets;
    cout << "Введите цену взрослого билета: ";
    cin >> newData.adultPrice;

    bool found = false;
    for (auto& p : performances) {
        if (p.name == newData.name) {
            p.showCount += newData.showCount;
            p.childTickets += newData.childTickets;
            p.childPrice = (p.childPrice + newData.childPrice) / 2;
            p.adultTickets += newData.adultTickets;
            p.adultPrice = (p.adultPrice + newData.adultPrice) / 2;
            found = true;
            break;
        }
    }

    if (!found) {
        performances.push_back(newData);
    }
}


void sortByChildPopularity() {
    sort(performances.begin(), performances.end(), 
        [](const Performance& a, const Performance& b) {
            return a.childTickets > b.childTickets;
        });
}

void sortByAdultPopularity() {
    sort(performances.begin(), performances.end(), 
        [](const Performance& a, const Performance& b) {
            return a.adultTickets > b.adultTickets;
        });
}

void sortByTotalProfit() {
    sort(performances.begin(), performances.end(), 
        [](const Performance& a, const Performance& b) {
            double profitA = a.childTickets * a.childPrice + a.adultTickets * a.adultPrice;
            double profitB = b.childTickets * b.childPrice + b.adultTickets * b.adultPrice;
            return profitA > profitB;
        });
}

void printPerformances() {
    cout << "\n" << setw(20) << left << "Спектакль" 
         << setw(10) << "Показов " 
         << setw(15) << "Дет. билеты " 
         << setw(10) << "Цена " 
         << setw(15) << "Взр. билеты " 
         << setw(10) << "Цена " 
         << setw(15) << "Общая прибыль " << endl;
    cout << string(95, '-') << endl;

    for (const auto& p : performances) {
        double totalProfit = p.childTickets * p.childPrice + p.adultTickets * p.adultPrice;
        cout << setw(5) << left << p.name 
             << setw(5) << p.showCount 
             << setw(5) << p.childTickets 
             << setw(5) << p.childPrice 
             << setw(5) << p.adultTickets 
             << setw(5) << p.adultPrice 
             << setw(5) << fixed << setprecision(2) << totalProfit << endl;
    }
}

int main() {
    const string filename = "performances.txt";
    loadDataFromFile(filename);

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить/обновить данные о спектакле\n";
        cout << "2. Показать популярность среди детей\n";
        cout << "3. Показать популярность среди взрослых\n";
        cout << "4. Показать общую прибыль по спектаклям\n";
        cout << "5. Показать все данные\n";
        cout << "6. Выйти и сохранить\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                updatePerformanceData();
                break;
            case 2:
                sortByChildPopularity();
                printPerformances();
                break;
            case 3:
                sortByAdultPopularity();
                printPerformances();
                break;
            case 4:
                sortByTotalProfit();
                printPerformances();
                break;
            case 5:
                printPerformances();
                break;
            case 6:
                saveDataToFile(filename);
                return 0;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }
}