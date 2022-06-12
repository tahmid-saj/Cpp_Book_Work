#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    auto pbeg = v.begin(), pend = v.end();
    auto beg = v.begin();

    //cout << *pbeg << "   " << beg;

    while (pbeg != v.end() && *beg >= 0) {
        cout << *(++pbeg) << endl;
    }

    unsigned long quiz1 = 0;

    cout << (quiz1 << 27);

    return 0;
}