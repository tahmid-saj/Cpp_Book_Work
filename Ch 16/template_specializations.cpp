#include <iostream>

using namespace std;

template <typename T> 
int compare(const T&, const T&) {
    return 1;
}

template <>
int compare(const char* const &p1, const char* const &p2) {
    return 2;
}

int main(void) {

    return 0;
}