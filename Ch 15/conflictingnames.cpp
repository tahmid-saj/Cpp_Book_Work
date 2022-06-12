#include <iostream>

using namespace std;

struct Base {
    Base() : mem(3) {}

protected:
    int mem;
};

struct Derived : Base {
    Derived(int i) : mem(i) {}

    int get_mem() {return mem;}
    int get_mem_base() {return Base::mem;}

protected:
    int mem;
};

int main(void) {
    Derived d(42);
    cout << d.get_mem() << endl;
    cout << d.get_mem_base() << endl;

    return 0;
}