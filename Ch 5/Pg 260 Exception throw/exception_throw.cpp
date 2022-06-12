#include <iostream>

using namespace std;

int main() {
    int item1, item2;

    item1 = 123;
    item2 = 124;

    try {
        if (item1 != item2) {
            throw runtime_error("Data must refer to same ISBN");
        }

        cout << item1 + item2 << endl;
    } catch (runtime_error err) {
        cout << err.what() << "Data must refer to the same ISBN";
    }

    return 0;
}