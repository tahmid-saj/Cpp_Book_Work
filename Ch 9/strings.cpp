#include <iostream>
#include <string>

using namespace std;

int main() {
    string arr[] = {"s", "k", "i"};
    string *cp = arr;
    string s2 = "hihello";

    string s(s2, 1);
    string s1(s2, 1, 4);

    string a;
    string b = "hello";
    a.insert(a.size(), 5, '!');

    cout << a << endl;

    string c = "some string", d = "other string";

    c.insert(0, d);

    cout << c << endl;
    
    c.insert(0, d, 0, d.size());

    cout << c << endl;
    int i = 42;

    string si = to_string(i);

    cout << si << endl;

    return 0;
}