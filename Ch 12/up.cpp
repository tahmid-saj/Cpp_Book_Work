#include <iostream>
#include <vector>
#include <memory>
#include <new>
#include <string>

using namespace std;

int main() {
    unique_ptr<int[]> up(new int[10]);
    //up.release();

    for (size_t i = 0; i != 10; i++) {
        up[i] = i;

        cout << ((int)up[i]) << endl;
    }

    shared_ptr<int> sp(new int[10], [](int *p) {delete [] p;});

    for (size_t i = 0; i != 10; i++) {
        *(sp.get() + i) = i;

        cout << *(sp.get() + i) << endl;
    }

    return 0;
}