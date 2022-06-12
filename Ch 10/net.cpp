#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vi = {1, -3, 4, -5};

    transform(vi.begin(), vi.end(), vi.begin(),
    [](int i) -> int {
        if (i < 0) {
            return -i;
        }
        else {
            return i;
        };
    });

    for (auto v : vi) {
        cout << v;
    }

    return 0;
}
