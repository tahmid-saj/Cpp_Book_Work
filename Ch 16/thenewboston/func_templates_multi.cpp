#include <iostream>

using namespace std;

template <class F, class S>
F smaller(F a, S b) {
    return (a < b) ? a : b;
}

int main(void) {
    int x = 89;
    double y = 56.78;
    
    cout << smaller(y, x) << endl;

    return 0;
}