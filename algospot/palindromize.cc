#include <algorithm>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string input;

int answer, n;

int pi[100000];
void failure() {
    int begin = 1, i = 0;
    while (begin + i < n) {
        if (input[begin + i] == input[(n - 1) - i]) {
            ++i;
            pi[begin + i - 1] = i;
        } else {
            if (i == 0) {
                begin++;
            } else {
                begin += i - pi[i - 1];
                i = pi[i - 1];
            }
        }
    }
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> input;
        n = input.size();
        failure();
        bool isPalindrome = true;
        for (int i = 0; i <= n / 2; i++) {
            if (input[i] != input[n - 1 - i]) {
                isPalindrome = false;
                break;
            }
        }
        if (isPalindrome) pi[n - 1] = n;
        cout << (2 * n - pi[n - 1]) << "\n";
    }
    return 0;
}