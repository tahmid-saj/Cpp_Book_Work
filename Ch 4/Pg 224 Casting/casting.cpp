#include <iostream>

using namespace std;

int main() {
    int j = 3, i = 4;
    double slope = static_cast<double>(j) / i;

    cout << slope << endl;

    //const char *pc;
    //char *p = const_cast<char*>(pc);

    int a = 70;
    int *ip = &a;
    char *pc = reinterpret_cast<char*>(ip);
    cout << *pc;

    int i = 3;

    if (i == 3) {
        int y = 4;
        cout << i;
    }

    return 0;
}