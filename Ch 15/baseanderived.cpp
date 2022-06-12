#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <set>

using namespace std;

class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {cout << "base";}
    
    virtual Quote* clone() const& {
        return new Quote(*this);
    }

    virtual Quote* clone() && {
        return new Quote(move(*this));
    }

    string isbn() const {
        return bookNo;
    }
    virtual double net_price(size_t n) const {
        cout << "base" << endl;
        return n * price;
    }
    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 1.0;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(size_t) const = 0;

    pair<size_t, double> discount_policy() const {
        return {quantity, discount};
    }

protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    using Disc_quote::Disc_quote;

    Bulk_quote() = default;
    Bulk_quote(const string &book, double price, size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}

    Bulk_quote* clone() const & {
        return new Bulk_quote(*this);
    }

    Bulk_quote* clone() && {
        return new Bulk_quote(move(*this));
    }

    double net_price(size_t cnt) const override {
        cout << "derived" << endl;
        if (cnt >= min_qty) {
            return cnt * (1 - discount) * price;
        }
        else {
            return cnt * price;
        }
    }

    virtual ~Bulk_quote() = default;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;

    return ret;
}

class Basket {
public:
    void add_item(const shared_ptr<Quote> &sale) {
        items.insert(sale);
    }

    void add_item(const Quote& sale) {
        items.insert(shared_ptr<Quote>(sale.clone()));
    }

    void add_item(Quote&& sale) {
        items.insert(shared_ptr<Quote>(move(sale).clone()));
    }

    double total_receipt(ostream& os) const {
        double sum = 0.0;

        for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
            sum += print_total(os, **iter, items.count(*iter));
        }

        os << "Total Sale: " << sum << endl;
        return sum;
    }

private:
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

int main(void) {
    /*
    Quote basic;
    Bulk_quote bulk;

    print_total(cout, basic, 20);
    print_total(cout, bulk, 30);

    // Pg 738
    Quote item;
    Bulk_quote bulk2;
    Quote *p = &item;
    p = &bulk2;
    Quote &r = bulk2;
    */

    // Pg 747
    Quote base("0-201-82470-1", 50);
    print_total(cout, base, 10);

    Bulk_quote derived("0-201-82470-1", 50, 5, 0.19);
    print_total(cout, derived, 10);

    base = derived;
    base.net_price(20);
    cout << endl;

    double undiscounted = base.Quote::net_price(44);

    Bulk_quote bulk;
    Bulk_quote *bulkP = &bulk;
    Quote *itemP = &bulk;

    bulkP->discount_policy();
    
    // destructors called
    Quote *itemPTest = new Quote;
    delete itemPTest;
    itemPTest = new Bulk_quote;
    delete itemPTest;

    // Pg 778
    cout << "----------------" << endl;
    vector<Quote> basket;
    basket.push_back(Quote("0-201-82", 50));

    basket.push_back(Bulk_quote("0-201-55", 50, 10, 0.25));
    cout << basket.back().net_price(15);

    // Pg 779
    cout << "----------------" << endl;
    vector<shared_ptr<Quote>> basket2;
    basket2.push_back(make_shared<Quote>("0-201-82", 50));
    basket2.push_back(make_shared<Bulk_quote>("0-201-55", 50, 10, 0.25));
    cout << basket2.back()->net_price(15) << endl;

    // Pg 782
    cout << endl << "----------------" << endl;
    Basket bsk;
    bsk.add_item(make_shared<Quote>("123", 45));
    bsk.add_item(make_shared<Bulk_quote>("345", 45, 3, 0.15));

    return 0;
}