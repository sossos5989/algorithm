#include <algorithm>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
string input[20000];

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input, input + n, [](const string &a, const string &b) {
        return (a.size() == b.size()) ? (a < b) : (a.size() < b.size());
    });
    cout << input[0] << "\n";
    for (int i = 1; i < n; i++) {
        if (input[i] != input[i - 1]) cout << input[i] << "\n";
    }
    return 0;
}