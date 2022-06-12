#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {0, 1, 2, 3, 4, 5};

    for (auto r_iter = vec.crbegin(); r_iter != vec.crend(); ++r_iter) {
        cout << *r_iter << endl;
    }

    return 0;
}