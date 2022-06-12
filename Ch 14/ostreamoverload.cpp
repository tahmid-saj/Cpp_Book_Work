#include <iostream>
#include <string>

using namespace std;

class Sales_data {
public:
    string isbn;
    int unitsSold;
    float revenue;
    float avgPrice;
};

ostream &operator<<(ostream &os, const Sales_data &item) {
    os << item.isbn << " " << item.unitsSold << " " << item.revenue << " " << item.avgPrice;
    return os;
}

int main(void) {
    Sales_data item1;
    item1.isbn = "bii";
    item1.unitsSold = 32;
    item1.revenue = 40.5;
    item1.avgPrice = 32.7;

    cout << item1;

    return 0;
}