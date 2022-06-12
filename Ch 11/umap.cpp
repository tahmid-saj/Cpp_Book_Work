#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Sales_data {
public:
    string isbn;
};

size_t hasher(const Sales_data &sd) {
    return hash<string>() (sd.isbn);
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn == rhs.isbn;
}

int main() {
    using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;
    SD_multiset bookstore(1, hasher, eqOp);
    Sales_data sales;
    sales.isbn = "hi";

    bookstore.insert(sales); 

    cout << (*bookstore.begin()).isbn << endl;

    return 0;
}