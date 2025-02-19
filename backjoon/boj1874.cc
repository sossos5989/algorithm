#include <iostream>
#include <stack>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, input, hi;
stack<int> s;
string answer;

int main() {
    fastIO;
    cin >> n;
    while (n--) {
        cin >> input;
        while (hi < input) {
            s.push(++hi);
            answer += "+\n";
        }
        if (s.top() != input) {
            answer = "NO";
            break;
        }
        s.pop();
        answer += "-\n";
    }
    cout << answer;
    return 0;
}