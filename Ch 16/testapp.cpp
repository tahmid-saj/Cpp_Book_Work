#include <iostream>

using namespace std;

template <typename IT>
void print(IT a) {
    cout << a << endl;
}

int main(void) {
    print(3);

    return 0;
}