#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 43, 42, 5};
    int val = 42;

    auto result = find(vec.cbegin(), vec.cend(), val);

    cout << *result;

    return 0;
}