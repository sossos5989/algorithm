#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int dp[1001][1001];

int main() {
    fastIO;
    string a, b;
    cin >> a >> b;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (a[i - 1] == b[j - 1])
                dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
        }
    }

    cout << dp[a.length()][b.length()];
    return 0;
}