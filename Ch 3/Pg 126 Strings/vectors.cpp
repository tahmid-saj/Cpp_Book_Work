#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    //vector<int> ivec;
    //vector<string> svec;
    vector<int> ivec(10, -1);
    vector<string> svec(10, "n");

    vector<int> v2;

    //pushing elements to a vector
    for (int i = 0; i != 100; ++i) {
        v2.push_back(i);
    }

    for (auto &i : v2) {
        i *= i;
    }

    for (auto i : v2) {
        cout << i << endl;
    }

    return 0;
}