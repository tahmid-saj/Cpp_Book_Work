#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_set>

struct Sales_data {
    std::string bookNo;
    int units_sold;
    int revenue;
};

namespace std {
    template <>
    struct hash<Sales_data> {
        typedef size_t result_type;
        typedef Sales_data argument_type;

        size_t operator() (const Sales_data& s) const;
    };

    size_t
    hash<Sales_data>::operator()(const Sales_data& s) const {
        return hash<std::string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);

    }
}

using namespace std;

int main(void) {
    unordered_multiset<Sales_data> SDset;

    return 0;
}