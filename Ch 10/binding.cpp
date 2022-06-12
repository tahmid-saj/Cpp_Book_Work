#include <iostream>
#include <functional>

using namespace std;

int call() {

    return 1;
}

int main() {
    auto newCall = bind(call);

    return 0;
}