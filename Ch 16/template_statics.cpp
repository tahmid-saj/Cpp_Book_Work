#include <iostream>

using namespace std;

template <typename T> class Foo;

template <typename T> class Foo {
public:
    static size_t count() { return ctr;}

private:
    static size_t ctr;
};


template <typename T>
size_t Foo<T>::ctr = 0;

int main(void) {
    Foo<string> fs;

    Foo<int> fi, fi2, fi3;

    auto ct = Foo<int>::count();

    ct = fi.count();

    cout << ct;

    return 0;
}