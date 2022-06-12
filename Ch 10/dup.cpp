#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());

    auto end_unique = unique(words.begin(), words.end());

    words.erase(end_unique, words.end());
}

int main() {
    vector<string> words = {"hi", "hello", "me", "me", "hi"};

    elimDups(words);
    
    for (auto &w : words) {
        cout << w;
    }

    return 0;
}