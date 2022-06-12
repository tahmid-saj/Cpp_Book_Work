#include <iostream>

using namespace std;

struct B;
struct A {
    A() = default;
    A(const B&);
};

struct B {
    operator A() const;
};


int main(void) {
    A f(const A&);
    B b;
    A a1 = f(b.operator A());
    A a2 = f(A(b));

    return 0;
}