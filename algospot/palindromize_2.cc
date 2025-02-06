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
        if (input[(n - 1) - (begin + i)] == input[(n - 1) - i]) {
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

void findKMP() {
    int begin = 0, i = 0;
    while (begin < n) {
        if (begin + i < n && input[begin + i] == input[(n - 1) - i]) {
            ++i;
            if (i + begin == n) {
                answer = i;
                return;
            }
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
        findKMP();
        cout << (2 * n - answer) << "\n";
    }
    return 0;
}