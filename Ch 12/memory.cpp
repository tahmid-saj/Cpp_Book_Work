#include <iostream>
#include <memory>
#include <vector>
#include <new>

using namespace std;

int main() {
    allocator<string> alloc;
    auto p = alloc.allocate(10);

    auto q = p;

    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hi");

    cout << *q << endl;

    return 0;
}