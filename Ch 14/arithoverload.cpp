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

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn == rhs.isbn && lhs.unitsSold == rhs.unitsSold && lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;

    sum.isbn += rhs.isbn;
    sum.avgPrice += rhs.avgPrice;
    sum.unitsSold += rhs.unitsSold;
    sum.revenue += rhs.revenue;

    return sum;
}

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

    Sales_data item2;
    item2.isbn = "kiihiii";
    item2.unitsSold = 35;
    item2.revenue = 40.6;
    item2.avgPrice = 32.9;

    Sales_data item3 = (item1 + item2);

    cout << (item1 + item2) << endl;

    cout << (item1 == item2) << endl;

    return 0;
}