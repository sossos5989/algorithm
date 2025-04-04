#include <cstring>
#include <iostream>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k;
int weight[101], value[101], dp[102][100001] = {0};

int main() {
    fastIO;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weight[i - 1]) {
                dp[i][j] =
                    max(dp[i][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
            }
        }
    }
    cout << dp[n][k];
    return 0;
}