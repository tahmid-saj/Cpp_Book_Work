#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    vector<int> c = {1, 2, 3, 4};
    vector<int>::iterator iter = c.begin();

    iter++;
    iter += 1;

    auto it = inserter(c, iter);

    *it = 5;
    *it = 6;


    for (auto val : c) {
        cout << val << endl;
    }

    return 0;
}