#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    friend void swap(HasPtr &, HasPtr&);

    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}

    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) {}

    HasPtr &operator=(const HasPtr &rhs) {
        auto newp = new string(*rhs.ps);
        delete ps;
        ps = newp;
        i = rhs.i;
        return *this;
    }

    HasPtr &operator=(HasPtr rhs) {
        swap(*this, rhs);
        return *this;
    }

    ~HasPtr() {delete ps;}

private:
    string *ps;
    int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main(void) {
    
    HasPtr v1, v2;

    
    

    return 0;
}