#include <iostream>
#include <utility>
#include <memory>

using namespace std;

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    
    StrVec(const StrVec & s) {
        auto newdata = alloc_n_copy(s.begin(), s.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
    }

    StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
        s.elements = s.first_free = s.cap = nullptr;
    }

    StrVec &operator=(const StrVec & rhs) {
        auto data = alloc_n_copy(rhs.begin(), rhs.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        
        return *this;
    }

    StrVec &operator=(StrVec &&rhs) noexcept {
        if (this != &rhs) {
            free();
            elements = rhs.elements;
            first_free = rhs.first_free;
            cap = rhs.cap;

            rhs.elements = rhs.first_free = rhs.cap = nullptr;
        }

        return *this;
    }

    // Overloaded assignment
    StrVec &operator=(initializer_list<string> il) {
        auto data = alloc_n_copy(il.begin(), il.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }

    // Overloaded subscripts
    string &operator[](size_t n) {
        return elements[n];
    }

    const string &operator[](size_t n) const {
        return elements[n];
    }

    ~StrVec() {
        free();
    }

    void push_back(const string& s) {
        chk_n_alloc();

        alloc.construct(first_free++, s);
    }

    void push_back(string &&s) {
        chk_n_alloc();
        alloc.construct(first_free++, std::move(s));
    }

    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    string *begin() const {return elements;}
    string *end() const {return first_free;};

private:
    allocator<string> alloc;
    void  chk_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }
    pair<string*, string*> alloc_n_copy(const string* b, const string* e) {
        auto data = alloc.allocate(e - b);

        return {data, uninitialized_copy(b, e, data)};
    }
    void free() {
        if (elements) {
            for (auto p = first_free; p != elements;) {
                alloc.destroy(--p);
            }

            alloc.deallocate(elements, cap - elements);
        }
    }

    void reallocate() {
        auto newcapacity = size() ? 2 * size() : 1;
        auto newdata = alloc.allocate(newcapacity);

        // For loop way
        /*
        auto dest = newdata;
        auto elem = elements;
        
        for (size_t i = 0; i != size(); i++) {
            alloc.construct(dest++, std::move(*elem++));
        }
        */
       
        auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), newdata);

        free();
        elements = newdata;
        first_free = last;
        cap = elements + newcapacity;
    }

    string *elements;
    string *first_free;
    string *cap;
};

int main(void) {

}