#include <iostream>

using namespace std;

int main() {
    string str("some string");

    //using a for range look
    for (auto c : str) {
        cout << c << endl;
    }

    //changing all characters in string to uppercase
    for (auto &c : str) {
        c = toupper(c);
    }

    cout << str;

    return 0;
}