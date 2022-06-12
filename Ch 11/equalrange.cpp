#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    multimap<string, int> bob = {{"hi", 1}, {"hello", 4},{"hello", 3}, {"bob", 5}};

    for (auto pos = bob.equal_range("hello"); pos.first != pos.second; ++pos.first) {
        cout << pos.first->second << endl;
    }

    return 0;
}