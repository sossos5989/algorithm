#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int list[400000];
int dp[400000];
100000 int main() {
    fastIO;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2 * n; i++) {
            cin >> list[i];
        }

        dp[0] = list[0];
        for (int i = 1; i < 2 * n; i++) {
            dp[i] = max(dp[i - 1])
        }
    }
    return 0;
}