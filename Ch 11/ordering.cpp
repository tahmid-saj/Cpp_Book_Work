#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class Sales_data {
public:
    bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
        return lhs.isbn < rhs.isbn;
    }

    string isbn;
};

int main() {
    multiset<Sales_data, decltype(Sales_data::compareIsbn)*> bookStore;


    return 0;
}