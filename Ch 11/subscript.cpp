#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    map<string, int> bob = {{"hi", 1}, {"hello", 3}};

    cout << bob["hi"];

    auto it = bob.begin();

    cout << it->second;

    return 0;
}