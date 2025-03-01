#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    string input;
    cin >> input;
    bool minus = false;
    int ptr = 0, answer = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '+' || input[i] == '-') {
            int k = stoi(input.substr(ptr, i - ptr));
            answer += minus ? -k : k;
            ptr = i + 1;
            if (input[i] == '-') minus = 1;
        }
    }
    int k = stoi(input.substr(ptr, input.size() - ptr));
    answer += minus ? -k : k;
    cout << answer;
    return 0;
}