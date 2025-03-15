#include <iostream>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, cache, print;
string input;
queue<int> q;

int main() {
    fastIO;
    cin >> n;
    while (n--) {
        cin >> input;
        if (input == "push") {
            cin >> cache;
            q.push(cache);
            continue;
        }
        if (input == "pop") {
            print = q.empty() ? -1 : q.front();
            if (!q.empty()) q.pop();
        }
        if (input == "size") print = q.size();
        if (input == "empty") print = q.empty();
        if (input == "front") print = q.empty() ? -1 : q.front();
        if (input == "back") print = q.empty() ? -1 : q.back();
        cout << print << "\n";
    }
    return 0;
}