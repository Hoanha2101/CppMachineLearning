#include <iostream>

using namespace std;

int main() {
    int *p = new int;
    *p = 42;
    cout << "Gia tri cua p: " << *p << endl;

    delete p;

    // Mang dong
    int n = 5;
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        arr[i] = i + 1;
    }
    cout << "Mang:";

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
}