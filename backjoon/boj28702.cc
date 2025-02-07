#include <iostream>
#include <string>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    string input, answer;
    bool isPrint = true;
    for (int i = 3; i > 0 && cin >> input; i--) {
        if (isPrint && input[0] <= '9') {
            int num = stoi(input) + i;
            if (num % 3 == 0) answer += "Fizz";
            if (num % 5 == 0) answer += "Buzz";
            if (answer.empty()) answer = to_string(num);
            isPrint = false;
        }
    }
    cout << answer;
    return 0;
}
