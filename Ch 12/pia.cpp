#include <iostream>
#include <vector>
#include <new>
#include <string>

using namespace std;

int main() {
    //int *pia = new int[get_size()];

    typedef int arrT[42];
    int *p = new arrT;

    int *pia = new int[10]();
    string *psa = new string[10]();

    int *pia3 = new int[4]{1, 2, 3, 4};

    ////////////////

    size_t n = 4;
    int *p4 = new int[n];

    for (int *q = p4; q != p4 + n; q++) {

    }

    delete [] p;

    return 0;
}