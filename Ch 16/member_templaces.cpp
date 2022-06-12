#include <iostream>
#include <memory>

using namespace std;

class DebugDelete {
public:
    DebugDelete(ostream &s = cerr) : os(s) {}

    template <typename T> void operator()(T *p) const {
        os << "deleting unique=ptr" << endl;
        delete p;
    }
private:
    ostream &os;
};

template <typename T>
class Blob {
public:
    template <typename IT>
    void f1(IT b, IT e);
};

template <typename T>
template <typename IT>
void Blob<T>::f1(IT b, IT e) {
    //cout << a << endl;
    data(make_shared<vector<T>>(b, e));
}

int main(void) {
    double *p = new double;
    DebugDelete d;
    d(p);

    int *ip = new int;
    DebugDelete()(ip);

    unique_ptr<int, DebugDelete> newi(new int, DebugDelete());
    unique_ptr<string, DebugDelete> sp(new string, DebugDelete());

    //Blob<int> test;
    //test.f1(3);

    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //list<const char*> w = {"now", "is", "the", "time"};

    //Blob<int> a1(begin(ia), end(ia));
    //Blob<int> a2(vi.begin(), vi.end());

    return 0;
}