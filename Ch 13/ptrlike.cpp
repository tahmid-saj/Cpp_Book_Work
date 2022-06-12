#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    friend void swap(HasPtr &, HasPtr&);

    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}

    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) {++*use;}

    HasPtr &operator=(const HasPtr& rhs) {
        ++*rhs.use;

        if (--*use == 0) {
            delete ps;
            delete use;
        }

        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }

    ~HasPtr() {
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }

//private:
    string *ps;
    int i;
    size_t *use;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main(void) {
    HasPtr v1;
    v1.i = 4;
    HasPtr v2;
    v2.i = 5;

    cout << v1.ps << "  " << v2.ps << endl;

    string *temp = v1.ps;
    v1.ps = v2.ps;
    v2.ps = temp;

    cout << v1.ps << "  " << v2.ps;

    return 0;
}