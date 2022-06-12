#include <iostream>
#include <string>

using namespace std;

class StrVec {
public:
    StrVec() {
        ele = "bobiiiiiiiiiiiiiiii";
        elements = &ele;
    }

    string ele = "bobiiii";
    string *elements = &ele;
    string *first_free;
    string *cap;
};

int main(void) {
    StrVec vec;
    size_t n = 3;

    cout << (*vec.elements)[n];

    return 0;
}