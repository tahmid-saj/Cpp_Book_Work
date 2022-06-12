#include <iostream>

using namespace std;

int main() {
    int arr[10];
    int *ptrs[10];
    int (*pt)[10] = &arr;
    int (&ref)[10] = arr;
    int *(&arry)[10] = ptrs;

    unsigned scores[11];
    unsigned grade;

    while (cin >> grade) {
        if (grade <= 100) {
            scores[grade / 10]++;
        }
    }

    for (auto i : scores) {
        cout << i << endl;
    }

    return 0;
}