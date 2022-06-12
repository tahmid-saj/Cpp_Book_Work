#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();

}


//[](const string &a, const string &b) { return a.size() < b.size(); }

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());

    auto end_unique = unique(words.begin(), words.end());

    words.erase(end_unique, words.end());
}

bool check_size(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = ' ') {
    elimDups(words);
    //stable_sort(words.begin(), words.end(), isShorter);
    stable_sort(words.begin(), words.end(), [] (const string &a, const string &b) {return a.size() < b.size();});

    /*
    auto wc = find_if(words.begin(), words.end(),
        [sz] (const string &a) {return a.size() >= sz;});
    */

    auto wc = find_if(words.begin(), words.end(),
    bind(check_size, _1, sz));

    auto count = words.end() - wc;
    cout << count << endl;

    for_each(wc, words.end(),
    [&os, c](const string &s) {os << s << c;});
    cout << endl;

}

ostream &print(ostream &os, const string&s, char c) {
    return os << s << c;
}

//stable_sort(words.begin(), words.end(), [] (const string &a, const string &b) {return a.size() < b.size();})

int main() {
    vector<string> words = {"hi", "hello", "me", "me", "hi"};

    //elimDups(words);
    //stable_sort(words.begin(), words.end(), isShorter);
    biggies(words, 2, cout, '.');

    auto check6 = bind(check_size, _1, 2);
    bool b1 = check6(words[1]);

    cout << b1 << endl;

    sort(words.begin(), words.end(), isShorter);
    sort(words.begin(), words.end(), bind(isShorter, _2, _1));

    ostream &ost = cout;

    for_each(words.begin(), words.end(),
    bind(print, ref(ost), _1, ' '));

    cout << endl;
    
    for (auto &w : words) {
        cout << w << ".";
    }
    

    return 0;
}