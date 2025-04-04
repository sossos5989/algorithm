#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int INF = 1e9;
int a, b;

int backtrack(int steps, int k) {
    if (k < a) return INF;
    if (k == a) return steps;
    int ret = INF;
    if (k % 2 == 0) ret = backtrack(steps + 1, k / 2);
    if (k % 10 == 1) ret = min(ret, backtrack(steps + 1, k / 10));
    return ret;
}

int main() {
    fastIO;
    cin >> a >> b;
    int ans = backtrack(1, b);
    cout << (ans == INF ? -1 : ans);
    return 0;
}