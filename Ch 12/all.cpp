#include <iostream>
#include <memory>
#include <vector>
#include <new>

using namespace std;

int main() {
    /*
    allocator<string> alloc;
    auto p = alloc.allocate(10);

    auto q = p;

    //alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    //alloc.construct(q++, "hi");

    cout << *p << endl;

    */
    allocator<int> alloc;
    vector<int> vi = {1, 2, 3, 4, 5};

    auto p = alloc.allocate(vi.size() * 2);

    auto q = uninitialized_copy(vi.begin(), vi.end(), p);

    uninitialized_fill_n(q, vi.size(), 42);

    cout << *(q + 3) << endl;

    return 0;
}