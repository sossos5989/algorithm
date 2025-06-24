#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int MOD = 1000000000;
int dp[1000001];

int main() {
    fastIO;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        dp[i] = 1;

    long long prev = dp[k] = k;

    for (int i = k; i <= n; i++) {
        dp[i] = prev;
        prev = (prev + prev - dp[i - k] + MOD) % MOD;
    }

    cout << dp[n];
    return 0;
}