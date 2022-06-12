#include <iostream>

using namespace std;

template <class T = int> class Numbers {
public:
    Numbers(T v = 0) : val(v) {}

private:
    T val;
};

template <typename T1, typename T2, typename T3>
T1 sum(T2 a, T3 b) {
    return a + b;
}

template <typename T1, typename T2, typename T3>
T3 alternative_sum(T2 a, T1 b) {
    return a + b;
}

int main(void) {
    Numbers<long double> lots_of_precision;
    Numbers<> average_precision;

    auto val3 = sum<int>(1, 3);
    cout << val3 << endl;

    long lng = 5;

    auto val2 = alternative_sum<long long, int, long>(3, lng);
    cout << val2 << endl;

    return 0;
}