#include <iostream>
#include <vector>
#include <new>

using namespace std;

int main() {
    int *pi = new (nothrow) int(1024);

    vector<int> *pv = new vector<int>{1, 2, 3, 4, 5, 6};

    delete pi;

    return 0;
}