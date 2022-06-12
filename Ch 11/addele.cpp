#include <iostream>
#include <utility>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec = {2, 4, 6, 7, 2, 4, 6, 8};
    set<int> set2;
    set2.insert(ivec.cbegin(), ivec.cend());
    set2.insert({1, 3, 5, 7, 1, 3, 5, 7});

    map<string, size_t> word_count;
    string word;

    while (cin >> word) {
        auto ret = word_count.insert({word, 1});
        //pair<map<string, size_t>::iterator, bool> ret =word_count.insert(make_pair(word, 1));

        if (!ret.second) {
            ++ret.first->second;
        }
    }

    

    return 0;
}