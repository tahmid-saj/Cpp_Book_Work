#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 43, 42, 5};
    vector<int> vec2 = {1, 2, 43, 42};
    int val = 42;

    int sum = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << sum << endl;
    cout << equal(vec.cbegin(), vec.cend(), vec2.cbegin()) << endl;

    fill(vec.begin(), vec.end(), 0);
    cout << *vec.begin() << endl;

    fill_n(vec.begin(), 5, 4);
    cout << *vec.begin() << endl;

    vector<int> vec3;

    auto it = back_inserter(vec3);
    *it = 42;
    *it = 45;
    fill_n(back_inserter(vec3), 10, 5);

    cout << vec3[11];

    return 0;
}