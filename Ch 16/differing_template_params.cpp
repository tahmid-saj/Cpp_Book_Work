#include <iostream>

using namespace std;

template <typename A, typename B>
int flexibleCompare(const A& v1, const B& v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

template <typename T> ostream &print(ostream &os, const T &obj) {
    return os << obj;
}

int main(void) {
    long lng;
    cout << flexibleCompare(lng, 1024) << endl;

    /// pg 838
    print(cout, 42);


    return 0;
}