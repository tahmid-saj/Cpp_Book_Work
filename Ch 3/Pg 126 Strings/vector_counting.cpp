#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<unsigned> scores(11, 0);
    unsigned grade;

    while (cin >> grade) {
        scores[grade / 10]++;
    }

    return 0;
}