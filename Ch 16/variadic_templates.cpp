#include <iostream>

using namespace std;

template <typename T, typename... Args>
void foo(const T &t, const Args&... rest);

template<typename T, typename... Args>
void foo(const T &t, const Args&... args) {
    cout << sizeof...(Args) << endl;
    cout << sizeof...(args) << endl;
    cout << endl;
}

int main(void) {
    int i = 0; double d= 3.14; string s = "how now brown cow";

    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");

    return 0;
}