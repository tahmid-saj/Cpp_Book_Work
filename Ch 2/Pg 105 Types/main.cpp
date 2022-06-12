#include <iostream>

using namespace std;

int main() {
    /*
    typedef double wages;
    typedef wages base, *p;

    using SI = double;

    auto i = 3 * 4;

    cout << sizeof(i) << endl;

    int a = 5;
    int c = 3;
    int &b = a;

    b = c;
    cout << b << endl;
    */

    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b;
    //int decltype(*p) c;

    return 0;
}