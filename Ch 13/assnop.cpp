#include <iostream>

using namespace std;

class Foo {
    public:
    Foo& operator=(const Foo& fooo) {
        this->f = fooo.f;
        return *this;
    }

    Foo &operator+(const Foo&) = delete;

    int f;
};

int main() {
    Foo fu, fo;
    fu.f = 6;
    fo.f = 5;

    fu = fo;
    cout << fu.f << endl;

    return 0;
}