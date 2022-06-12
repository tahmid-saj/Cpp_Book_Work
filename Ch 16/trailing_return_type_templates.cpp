#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <utility>

using namespace std;

template <typename It>
auto fcn(It beg, It end) -> typename remove_reference<decltype(*beg)>::type {
    return *beg;
}

template <typename T> 
int compare846(const T&, const T&);

template <typename T>
void f3(T&& a) {
    cout << 5;
}

void f(int v1, int &v2) {
    cout << v1 << " " << ++v2 << endl;
}

template <typename F, typename T1, typename T2>
void flip1(F f, T1 &&t1, T2 &&t2) {
    f(forward<T2>(t2), forward<T1>(t1));
}

template <typename Type> 
void intermediary(Type &&arg) {
    finalFcn(std::forward<Type>(arg));
}

int main(void) {
    vector<int> vi = {1, 2, 3, 4, 5};
    
    auto i = fcn(vi.begin(), vi.end());

    cout << i << endl;

    ////////////////////// Pg 846
    //int (*pf1)(const int&, const int&) = compare846;

    f3(42);
    f3(i);

    return 0;
}