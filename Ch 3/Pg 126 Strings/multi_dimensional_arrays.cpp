#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

int main() {
    int ia[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}; 

    for (auto p = ia; p != ia + 3; p++) {
        for (auto q = *p; q != *p + 4; q++) {
            cout << *q << ' ';
        }
        cout << endl;
    }

    //stack<int> stack1;
    stack<int, vector<int> > stack2; 
    stack<int, list<int>> stack3;

    return 0;
}