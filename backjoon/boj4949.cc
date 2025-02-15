#include <iostream>
#include <stack>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string input;

int main() {
    fastIO;
    while (1) {
        getline(cin, input);
        if (input == ".") break;
        stack<char> s;
        for (int i = 0; input[i] != '.'; i++) {
            char &cand = input[i];
            char top = s.empty() ? '?' : s.top();
            if (cand == '(' | cand == '[')
                s.push(cand);
            else if (top == '(' && cand == ')' || top == '[' && cand == ']')
                s.pop();
            else if (top != '(' && cand == ')' || top != '[' && cand == ']') {
                s.push('?');
                break;
            }
        }
        cout << (s.empty() ? "yes\n" : "no\n");
    }
    return 0;
} // 조금 난해한 코드