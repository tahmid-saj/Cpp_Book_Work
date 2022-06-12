#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    /*
    int i = 10;
    int g = 11;

    auto sayHello = [=, &i] (int a, int b) -> int {
 
        return a + b + i + g;
    };

    cout << sayHello(3, 4);
    */

    vector<int> arr = {1, 2, 3, 4, 5};
    double total = 0;

    std::for_each(begin(arr), end(arr), 
    [&](int x) {
    total += x;
    });

    cout << "Sum is " << total << endl;

    return 0;
}