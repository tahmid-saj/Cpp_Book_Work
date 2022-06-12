#include <iostream>
#include <vector>

using namespace std;

int main() {
    int int_arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> ivec(begin(int_arr), end(int_arr));

    return 0;
}