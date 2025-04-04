#include <algorithm>
#include <iostream>
#include <string>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, list[8], used[8];
void backtrack(int len, string stack) {
    if (len == 0) {
        cout << stack << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 1) continue;
        used[i] = 1;
        backtrack(len - 1, stack + to_string(list[i]) + " ");
        used[i] = 0;
    }
}

int main() {
    fastIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    sort(list, list + n);
    backtrack(m, "");
    return 0;
}