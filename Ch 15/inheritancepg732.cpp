#include <iostream>
#include <string>

using namespace std;

class Quote {
public:
    string isbn() const {
        return isbnNum;
    }
    virtual double net_price(size_t n) const {
        cout << "base" << endl;
        return n;
    }
    string isbnNum = "123";
};

class Bulk_quote : public Quote {
public:
    
    double net_price(size_t n) const override {
        cout << "derived" << endl;
        return n;
    }
    
};

double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;

    return ret;
}

int main(void) {
    Quote basic;
    Bulk_quote bulk;

    print_total(cout, basic, 20);
    print_total(cout, bulk, 30);

    return 0;
}