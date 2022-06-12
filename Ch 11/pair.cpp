#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

pair<string, int> process(vector<string> &v) {
    if (!v.empty()) {
        return {v.back(), v.back().size()};
        //return pair<string, int>(v.back(), v.back().size());
    }
    else {
        return pair<string, int>();
    }
}

int main() {
    vector<string> v = {"hi", "hello"};
    cout << process(v).first << process(v).second;

    return 0;
}
