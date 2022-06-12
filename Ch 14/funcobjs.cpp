#include <iostream>
#include <functional>

using namespace std;

int main() {
    plus<int> intAdd;
    negate<int> intNegate;

    int sum = intAdd(10, 20);
    cout << sum << endl;
    sum = intNegate(intAdd(10, 20));
    cout << sum << endl;
    sum = intAdd(10, intNegate(10));
    cout << sum << endl;

    greater<int> gt;
    int g = gt(50, 30);
    cout << g << endl;

    return 0;
}