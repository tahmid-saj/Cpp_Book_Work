#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    
    vector<int> vec = {1, 2, 3};
    /*
    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;

    while (in_iter != eof) {
        vec.push_back(*in_iter++);
    }

    for (auto val : vec) {
        cout << val;
    }
    */

    ostream_iterator<int> out_iter(cout, " ");

    for (auto e : vec) {
        *out_iter++ = e;
    }

    cout << endl;

    return 0;
}