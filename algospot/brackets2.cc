#include <iostream>
#include <stack>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// 아스키 코드로 [](91, 93), ()(40, 41), {}(123, 125)

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        string input;
        cin >> input;
        stack<char> s;
        for (int i = 0; i < input.size(); i++) {
            if (!s.empty() &&
                (input[i] - s.top() == 2 || input[i] - s.top() == 1))
                s.pop();
            else
                s.push(input[i]);
        }
        cout << (s.empty() ? "YES" : "NO") << endl;
    }
}

// for문에 break문을 잘 걸면 조금 더 빨라짐