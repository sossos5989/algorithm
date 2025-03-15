#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string input = "bla";

int main() {
    fastIO;
    while (true) {
        cin >> input;
        if (input == "0") break;
        bool answer = true;
        for (int i = 0; i < input.size() - i - 1; i++) {
            if (input[i] != input[input.size() - i - 1]) {
                answer = false;
                break;
            }
        }
        cout << (answer ? "yes\n" : "no\n");
    }
    return 0;
}