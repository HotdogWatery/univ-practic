#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

string readTextFromFile(const string& filename) {
    ifstream file(filename);
    string text;
    string line;
    
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return "";
    }
    
    while (getline(file, line)) {
        text += line + " ";
    }
    
    file.close();
    return text;
}

vector<string> splitSentences(const string& text) {
    vector<string> sentences;
    string current;
    
    for (char ch : text) {
        current += ch;
        if (ch == '.' || ch == '!' || ch == '?') {
            while (!current.empty() && isspace(current.front())) {
                current.erase(current.begin());
            }
            if (!current.empty()) {
                sentences.push_back(current);
            }
            current.clear();
        }
    }
    
    if (!current.empty()) {
        sentences.push_back(current);
    }
    
    return sentences;
}

int countWords(const string& sentence) {
    istringstream iss(sentence);
    int count = 0;
    string word;
    
    while (iss >> word) {
        count++;
    }
    
    return count;
}

double averageWordsPerSentence(const string& filename) {
    string text = readTextFromFile(filename);
    if (text.empty()) return 0.0;
    
    vector<string> sentences = splitSentences(text);
    if (sentences.empty()) return 0.0;
    
    int totalWords = 0;
    for (const string& sentence : sentences) {
        totalWords += countWords(sentence);
    }
    
    return static_cast<double>(totalWords) / sentences.size();
}

void processTextFile(const string& inputFile, const string& outputFile) {
    string text = readTextFromFile(inputFile);
    if (text.empty()) return;
    
    ofstream fout(outputFile);
    if (!fout.is_open()) {
        cerr << "Ошибка открытия файла " << outputFile << endl;
        return;
    }
    
    vector<string> sentences = splitSentences(text);
    for (const string& sentence : sentences) {
        fout << sentence << "\n";
    }
    
    fout.close();
}

int main() {
    const string inputFile = "F1.txt";
    const string outputFile = "F2.txt";
    
    double avg = averageWordsPerSentence(inputFile);
    cout << "Среднее число слов в предложениях: " << avg << endl;
    
    processTextFile(inputFile, outputFile);
    cout << "Предложения из " << inputFile << " записаны в " << outputFile 
         << " по одному в строке." << endl;
    
    return 0;
}