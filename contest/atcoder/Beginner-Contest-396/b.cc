#include <iostream>
#include <stack>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;

    int q, label;
    stack<int> s;
    for (int i = 0; i < 100; i++) {
        s.push(0);
    }

    while (n--) {
        cin >> q;
        if (q == 2) {
            cout << s.top() << "\n";
            s.pop();
        } else {
            cin >> label;
            s.push(label);
        }
    }
    return 0;
}