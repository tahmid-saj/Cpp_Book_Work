#include <iostream>

using namespace std;

struct D2 {
    virtual void f1(int) const final;
};

struct D3 : D2 {
    void f2();
    // void f1(int) const; error
};

int main(void) {

    return 0;
}