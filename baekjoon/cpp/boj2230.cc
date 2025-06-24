#include <algorithm>
#include <iostream>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, list[100000];

int main() {
    fastIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> list[i];

    sort(list, list + n);
    int ans = 2 * 1e9;
    for (int i = 0; i < n - 1; i++) {
        auto it = lower_bound(list + i, list + n, list[i] + m);
        if (it != list + n) ans = min(ans, *it - list[i]);
    }

    cout << ans;
    return 0;
} // 사실 투포인터로 풀어도 되긴 함