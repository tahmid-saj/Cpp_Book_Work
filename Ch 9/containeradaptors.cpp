#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int main() {
    deque<int> deq;
    stack<int> stk(deq);

    stack<string, vector<string>> str_stk;

    queue<int> qu;

    qu.push(9);
    qu.push(7);

    cout << qu.front();

    return 0;
}