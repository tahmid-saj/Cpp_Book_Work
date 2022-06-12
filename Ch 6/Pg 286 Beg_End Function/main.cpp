#include <iostream>

using namespace std;

void print(const int *beg, const int *end) {
    while (beg != end) {
        cout << *beg++ << endl;
    }
}

int main() {
    int arr[] = {8, 2, 3, 4, 5};
    auto b = arr;
    auto e = arr + 5;

    print(begin(arr), end(arr));

    return 0;
}