#include <iostream>

using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *p = arr;
    p++;
    cout << *p << endl;

    int *beg = begin(arr);
    int *last = end(arr);

    return 0;
}