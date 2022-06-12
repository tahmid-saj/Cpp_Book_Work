#include <iostream>
#include <vector>

using namespace std;

//template <typename T> int compare(const T&, const T&);
template <typename T> class Blob;

template <typename T> T calc(const T&, const T&);
template <typename U> U calc(const U&, const U&);

template <typename Type>
Type calc(const Type& a, const Type& b) {
}

template <typename T, typename F = less<T>>
typename T::value_type top(const T& c) {
    if (!c.empty()) {
        return c.back();
    }
    else {
        return typename T::value_type();
    }
}

//////////// Pg 826

template <typename T, typename F = less<T>>
int compare(const T &v1, const T &v2, F f = F()) {
    if (f(v1, v2)) return -1;
    if (f(v2, v1)) return 1;
    return 0;
}

int main(void) {
    vector<int> vi;
    cout << top(vi) << endl;;

    cout << compare(0, 42) << endl;

    return 0;
}