#include <iostream>

using namespace std;

template <typename T> class Bob;

template <typename T>
class Bob {
public:
    template <typename IT>
    void print(IT a) {
        cout << a << endl;
    }
};

template <typename IT>
void print(IT a) {
    cout << a << endl;
}

template class Bob<int>;
template <typename IT> void print(int);
