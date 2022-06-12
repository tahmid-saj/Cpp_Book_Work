#include <iostream>
#include <memory>
#include <vector>
#include <list>

using namespace std;

//////////////////////// declarations for friend declarations in Blob

template <typename T> class BlobPtr;
template <typename T> class Blob;
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);

//////////////////////// Blob

template <typename T> class Blob {
public:
    friend class BlobPtr<T>;
    friend bool operator==<T> (const Blob<T>&, const Blob<T>&);

    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob();
    Blob(initializer_list<T> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }

    void pop_back();

    T& back();
    T& operator[](size_type i);
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const string &msg) const;
};

template <typename T>
Blob<T>::Blob() : data(make_shared<vector<T>>()) {}

template <typename T>
Blob<T>::Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T> void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

///////////////////////////// BlobPtr

template <typename T> class BlobPtr {
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    BlobPtr& operator++();
    BlobPtr<T>& operator++(int);

    BlobPtr& operator--();

private:
    shared_ptr<vector<T>> check(size_t, const string&) const;
    weak_ptr<vector<T>> wptr;
    size_t curr;
};

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

///////////// Pg 821

template<typename T> using twin = pair<T, T>;
template<typename T> using partNo = pair<T, unsigned>;

int main(void) {
    twin<string> authors;
    partNo<string> books;

    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<const char*> w = {"now", "is", "the", "time"};

    //Blob<int> a1(begin(ia), end(ia));
    //Blob<int> a2(vi.begin(), vi.end());

    return 0;
}