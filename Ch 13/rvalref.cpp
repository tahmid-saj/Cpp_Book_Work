#include <iostream>

using namespace std;

int main(void) {
    int i = 42;

    const int &r3 = i * 42;
    int &&rr2 = i * 42;

    int &&rr3 = std::move(rr2);

    return 0;
}