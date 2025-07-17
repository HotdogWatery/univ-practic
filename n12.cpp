#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

struct Worker {
    string lastName;
    string firstName;
    string middleName;
    int rank;
    double ratePerUnit;
    int unitsProduced;
};

struct DailyReport {
    string date;
    int totalUnits;
    double totalPayment;
};

Worker inputWorkerData() {
    Worker w;
    cout << "Введите фамилию: ";
    cin >> w.lastName;
    cout << "Введите имя: ";
    cin >> w.firstName;
    cout << "Введите отчество: ";
    cin >> w.middleName;
    cout << "Введите разряд: ";
    cin >> w.rank;
    cout << "Введите расценку за единицу: ";
    cin >> w.ratePerUnit;
    cout << "Введите количество произведенных изделий: ";
    cin >> w.unitsProduced;
    return w;
}

void printPayroll(const vector<Worker>& workers) {
    cout << "\nРасчетная ведомость:\n";
    cout << setw(25) << left << "ФИО" 
         << setw(10) << "Разряд" 
         << setw(10) << "Расценка" 
         << setw(15) << "Количество" 
         << setw(10) << "Сумма" << endl;
    cout << string(70, '-') << endl;

    for (const auto& w : workers) {
        double sum = w.ratePerUnit * w.unitsProduced;
        cout << setw(25) << left << (w.lastName + " " + w.firstName + " " + w.middleName)
             << setw(10) << w.rank
             << setw(10) << fixed << setprecision(2) << w.ratePerUnit
             << setw(15) << w.unitsProduced
             << setw(10) << fixed << setprecision(2) << sum << endl;
    }
}

DailyReport calculateDailyReport(const vector<Worker>& workers) {
    DailyReport report;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    report.date = to_string(ltm->tm_mday) + "." + to_string(1 + ltm->tm_mon) + "." + to_string(1900 + ltm->tm_year);
    
    report.totalUnits = 0;
    report.totalPayment = 0.0;
    
    for (const auto& w : workers) {
        report.totalUnits += w.unitsProduced;
        report.totalPayment += w.ratePerUnit * w.unitsProduced;
    }
    
    return report;
}

void printDailyReport(const DailyReport& report) {
    cout << "\nДневная сводка:\n";
    cout << setw(15) << left << "Дата" 
         << setw(25) << "Произведено (количество)" 
         << setw(15) << "Оплачено" << endl;
    cout << string(55, '-') << endl;
    cout << setw(15) << left << report.date
         << setw(25) << report.totalUnits
         << setw(15) << fixed << setprecision(2) << report.totalPayment << endl;
}

void saveToFile(const vector<Worker>& workers, const DailyReport& report) {
    ofstream outFile("daily_report.txt");
    if (outFile.is_open()) {
        outFile << "Расчетная ведомость:\n";
        outFile << setw(25) << left << "ФИО" 
                << setw(10) << "Разряд" 
                << setw(10) << "Расценка" 
                << setw(15) << "Количество" 
                << setw(10) << "Сумма" << "\n";
        outFile << string(70, '-') << "\n";

        for (const auto& w : workers) {
            double sum = w.ratePerUnit * w.unitsProduced;
            outFile << setw(25) << left << (w.lastName + " " + w.firstName + " " + w.middleName)
                    << setw(10) << w.rank
                    << setw(10) << fixed << setprecision(2) << w.ratePerUnit
                    << setw(15) << w.unitsProduced
                    << setw(10) << fixed << setprecision(2) << sum << "\n";
        }

        outFile << "\nДневная сводка:\n";
        outFile << setw(15) << left << "Дата" 
                << setw(25) << "Произведено (количество)" 
                << setw(15) << "Оплачено" << "\n";
        outFile << string(55, '-') << "\n";
        outFile << setw(15) << left << report.date
                << setw(25) << report.totalUnits
                << setw(15) << fixed << setprecision(2) << report.totalPayment << "\n";

        outFile.close();
        cout << "Данные сохранены в файл daily_report.txt" << endl;
    } else {
        cout << "Не удалось открыть файл для записи!" << endl;
    }
}

int main() {
    vector<Worker> workers;
    char addMore;

    do {
        Worker w = inputWorkerData();
        workers.push_back(w);

        cout << "Добавить еще одного работника? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    printPayroll(workers);

    DailyReport report = calculateDailyReport(workers);
    printDailyReport(report);

    saveToFile(workers, report);

    return 0;
}