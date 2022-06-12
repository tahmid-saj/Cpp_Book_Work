#include <iostream>
#include <string>

using namespace std;

int main() {
    string s7(10, 'c'); //direct initialization
    string s8 = string(10, 'c'); //copy initialization

    string s1, s2;

    cin >> s1 >> s2;
    cout << s1 << s2 << endl;

    while (cin >> s2) {
        cout << s2 << endl;
    }

    while (getline(cin, s2)) {
        cout << s2 << endl;
    }

    return 0;
}