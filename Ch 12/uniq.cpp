#include <iostream>
#include <memory>
#include <new>

using namespace std;

int main() {
    unique_ptr<string> p1;
    //unique_ptr<int> p2(new int(42));

    unique_ptr<string> p2(p1.release());
    unique_ptr<string> p3(new string("Trex"));

    p2.reset(p3.release());

    //cout << *p1 << endl;
    cout << *p2 << endl;
    //cout << *p3 << endl;

    return 0;
}