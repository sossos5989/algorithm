#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, input[500][500], dp[501][501];

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> input[i][j];

    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + input[i][j];

    cout << dp[0][0];

    return 0;
}