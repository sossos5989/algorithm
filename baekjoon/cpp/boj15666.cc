#include <algorithm>
#include <iostream>
#include <string>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, list[8];

void backtrack(int prev, int len, string stack) {
    if (len == 0) {
        cout << stack << '\n';
        return;
    }
    int cache = -1;
    for (int i = 0; i < n; i++) {
        if (cache == list[i] || prev > list[i]) continue;
        cache = list[i];
        backtrack(list[i], len - 1, stack + to_string(list[i]) + " ");
    }
}

int main() {
    fastIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    sort(list, list + n);
    backtrack(0, m, "");
    return 0;
}