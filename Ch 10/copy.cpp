#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int a1[] = {0, 1, 2, 3, 4, 5, 6};
    int a2[sizeof(a1) / sizeof(*a1)];

    auto ret = copy(begin(a1), end(a1), a2);
    cout << *ret << endl;

    list<int> lst = {1, 2, 3, 4, 5, 5};

    replace(lst.begin(), lst.end(), 5, 4);
    cout << lst.back();

    return 0;
}