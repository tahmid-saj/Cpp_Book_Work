#include <iostream>

using namespace std;

struct absInt {
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' ') : os(o), sep(c) {} 

    void operator()(const string &s) const {os << s << ' ';}
public:
    ostream &os;
    char sep;
    
};

int main(void) {
    int i = -42;
    absInt absObj;
    int ui = absObj(i);

    string s = "hii";
    PrintString printer;
    printer(s);

    PrintString errors(cerr, '\n');
    errors(s);

    return 0;
}