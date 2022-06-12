#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> text = {"h", "e", "l", ".", "l", "o", "\n", "I"};

    for (const auto &s : text) {
        cout << s;

        if (s.empty() || s[s.size() - 1] == '.') {
            cout << endl;
        }
        else {
            cout << " ";
        }
    }

    return 0;
}