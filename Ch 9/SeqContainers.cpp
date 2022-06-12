#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <array>

using namespace std;

int main() {
    vector<vector<string>> lines;

    //Declaring an iterator
    list<string>::iterator iter;

    //Declaring distance type
    vector<int>::difference_type count;

    //Declaring an array container
    array<int, 3> arr;
    vector<const char*> articles = {"a", "ae", "asfa"};

    forward_list<string> words(articles.begin(), articles.end());

    array<int, 4> inArr = {1, 2, 3, 4};
    array<int, 4> incopyArr = inArr;

    list<int> lI = {1, 2, 3, 4, 5};

    list<int>::iterator it = lI.begin();

    auto it2 = std::next(it, 1);

    cout << *it << "    " << *it2 << endl;
}