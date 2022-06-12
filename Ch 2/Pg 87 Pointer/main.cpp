#include <iostream>

using namespace std;

int main() {
    int *ptr1 = nullptr;

    int *ptr;
    int* ptr2;

    int i = 42;
    int *&r = ptr2;
    r = &i;

    const int ci = 1024;
    const int &r1 = ci;
    const int &r2 = ci;

    return 0;
}