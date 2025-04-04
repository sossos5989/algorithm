#include <iostream>
#include <string>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
void backtrack(int prev, int len, string stack) {
    if (len == 0) {
        cout << stack << '\n';
        return;
    }
    for (int i = prev; i <= n; i++) {
        backtrack(i, len - 1, stack + to_string(i) + " ");
    }
}

int main() {
    fastIO;
    cin >> n >> m;
    backtrack(1, m, "");
    return 0;
}