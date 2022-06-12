#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s("some string");

    //make the first letter in s an uppercase
    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = toupper(*it);
    }

    return 0;
}