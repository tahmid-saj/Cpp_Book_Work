#include <iostream>

using namespace std;

template <class T>
class Spunky {
public:
    Spunky(T x) {
        cout << x << " is not a character!" << endl;
    }
};

template <>
class Spunky<char> {
public:
    Spunky(char x) {
        cout << x << " is a character!" << endl;
    }
};

int main(void) {
    Spunky<int> ia(3);
    Spunky<double> da(3.145);
    Spunky<char> ca('c');

    return 0;
}