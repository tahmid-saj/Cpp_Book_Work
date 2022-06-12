#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(void) {
    int n = 4;
    allocator<string> alloc;
    auto p = alloc.allocate(n);

    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hi");

    alloc.construct(q, "eee");

    // Printing
    cout << *(q - 2) << endl;
    //cout << *q << endl; error

    return 0;
}