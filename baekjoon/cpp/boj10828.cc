#include <iostream>
#include <stack>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, cache, print;
string input;
stack<int> s;

int main() {
    fastIO;
    cin >> n;
    while (n--) {
        cin >> input;
        if (input == "push") {
            cin >> cache;
            s.push(cache);
            continue;
        }
        if (input == "size") {
            print = s.size();
        }
        if (input == "empty") {
            print = s.empty();
        }
        if (input == "top" || input == "pop") {
            print = s.empty() ? -1 : s.top();
            if (!s.empty() && input == "pop") s.pop();
        }
        cout << print << "\n";
    }
    return 0;
}