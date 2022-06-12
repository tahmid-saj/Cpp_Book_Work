#include <iostream>
#include <vector>
#include <memory>
#include <new>

using namespace std;

class StrBlobPtr;
//class StrBlob;

class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) {}
    //StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    string &deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    StrBlobPtr &incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;

        return *this;
    }

private:
    shared_ptr<vector<string>> check(size_t i, const string& msg) const {
        auto ret = wptr.lock();// is thevectorstill around?
        
        if (!ret) {
            throw std::runtime_error("unbound StrBlobPtr");
        } 
        
        if (i >= ret->size()) {
            throw std::out_of_range(msg);
        }
        
        return ret; // otherwise, return ashared_ptrto thevector
    }

    weak_ptr<vector<string>> wptr;
    size_t curr;
};

/*
class StrBlob {
    friend class StrBlobPtr;

    StrBlobPtr begin() {return StrBlobPtr(*this);}
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }
}
*/

int main() {
    shared_ptr<int> p = make_shared<int>(42);
    weak_ptr<int> wp(p);

    return 0;
}