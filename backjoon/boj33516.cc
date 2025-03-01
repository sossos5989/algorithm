#include <iostream>
#include <stack>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, state = 0, count = 0;
    string input;
    stack<int> s; // 상태를 저장.
    cin >> n >> input;
    for (int i = 0; i < n; i++) {
        if (input[i] == 's') {
            if (state != 0) s.push(state);
            state = 1;
        } else if (input[i] == 'k' && state == 1 ||
                   input[i] == 'e' && state == 2 ||
                   input[i] == 'e' && state == 3 ||
                   input[i] == 'p' && state == 4) {
            state++;
        } else {
            while (!s.empty())
                s.pop();
            state = 0;
        }
        while (state == 5) {
            count++;
            state = s.empty() ? 0 : (s.top() + 1);
            if (!s.empty()) s.pop();
        }
    }
    cout << count;
    return 0;
}