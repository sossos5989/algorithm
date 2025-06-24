#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int ans = 0;
        ans = max(ans, n * (m / 2) + (n % 2 ? ((m + 1) / 2) : 0));
        ans = max(ans, m * (n / 2) + (m % 2 ? ((n + 1) / 2) : 0));
        cout << ans << '\n';
    }
    return 0;
}