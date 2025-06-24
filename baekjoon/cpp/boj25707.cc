#include <algorithm>
#include <iostream>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, list[1001];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> list[i];

    sort(list, list + n);
    int ans = list[n - 1] - list[0];
    for (int i = 0; i < n - 1; i++)
        ans += list[i + 1] - list[i];

    cout << ans;
    return 0;
}