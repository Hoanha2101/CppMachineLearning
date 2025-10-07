#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        ifstream file("./../../data/data.txt");
        if (!file.is_open()) {
            throw runtime_error("Could not open file");
        }

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}