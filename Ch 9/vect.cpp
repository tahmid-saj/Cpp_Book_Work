#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
    vector<float> x;
    string xi;

    while (cin >> xi) {
        if (xi == std::string("last")) {
            break;
        }

        x.push_back(stof(xi));
    }


    for (auto i = x.begin(); i != x.end(); i++) {
        cout << *i;
    }

    return 0;
}