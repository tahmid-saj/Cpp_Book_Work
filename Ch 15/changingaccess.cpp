#include <iostream>

using namespace std;

class Base {
public:
    size_t size() const { return n;}
protected:
    size_t n;
private:
    int test;
};

class Derived : private Base {
public:
    using Base::size;
protected:
    using Base::n;
    //using Base::test;
};

int main(void) {


    return 0;
}