#include <iostream>

using namespace std;

class Base {
public:
    static void statmem();

};

class Derived : public Base {
    void f(const Derived &derived_obj) {
        Base::statmem();
        Derived::statmem();

        derived_obj.statmem();
        statmem();
    }
};

int main(void) {

    return 0;
}


