#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

int add(int a, int b) {
    return a + b;
}

struct div {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main(void) {
    auto mod = [](int i, int j) {
        return i % j;
    };

    //map<string, int(*)(int, int)> binops;
    //struct div dividing;
    //map<string, function<int(int, int)>> binops;

    map<string, function<int(int, int)>> binops = {
        {"+", add},
        {"-", minus<int>()},
        {"*", [](int i, int j) {return i * j;}},
        {"%", mod}
    };

    cout << binops["+"](10, 5) << endl;
    cout << binops["-"](10, 5) << endl;
    cout << binops["*"](10, 5) << endl;
    cout << binops["%"](10, 5) << endl;

    return 0;
}