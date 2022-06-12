#include <iostream>

using namespace std;

class SmallInt {
public:
    SmallInt(int i = 0) : val(i) {
        if (i < 0 || i > 255) {
            throw std::out_of_range("Bad smallint value");
        }
    }
    explicit operator int() const {return val;}

private:
    size_t val;
};

int main(void) {
    SmallInt si;
    si = 4;
    // si + 3;
    static_cast<int>(si) + 3;

    return 0;
}