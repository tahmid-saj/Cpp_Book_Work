#include <iostream>
#include <memory>
#include <new>

using namespace std;

shared_ptr<int> clone(int p) {
    return shared_ptr<int>(new int(p));
}

int main() {
    shared_ptr<int> p1(new int(1024));

    p1.reset(new int(1024));

    shared_ptr<int> p2;
    p2.reset(new int(*p1));

    cout << p1.use_count();

    return 0;
}