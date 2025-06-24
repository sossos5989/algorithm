#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, w, board[10000][2], dp[4][4];

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> w;
        for (int j = 0; j < 2; j++)
            for (int i = 0; i < n; i++)
                cin >> board[i][j];

        dp[1][0] = 1, dp[0][1] = 1;
        dp[1][1] = board[0][0] + board[0][1] <= w ? 2 : 1;
        for (int i = 2; i <= 3; i++) {
            int &ret1 = dp[(i - 1) % 4][i % 4];
            ret1 = dp[(i - 1) % 4][(i - 1) % 4] + 1;
            if (board[(i - 1) % 4][1] + board[(i - 1) % 4][1] <= w)
                ret1 = min(ret1, dp[(i - 1) % 4][(i - 2) % 4] + 1);

            int &ret2 = dp[i % 4][(i - 1) % 4];
            ret2 = dp[(i - 1) % 4][(i - 1) % 4] + 1;
            if (board[(i - 1) % 4][0] + board[(i - 1) % 4][0] <= w)
                ret2 = min(ret2, dp[(i - 2) % 4][(i - 1) % 4] + 1);

            int &ret3 = dp[i % 4][i % 4];
            ret3 = dp[(i - 1) % 4][(i - 1) % 4] + 2;
            int sum = board[(i - 1) % 4][0] + board[(i - 1) % 4][1];
            if (sum <= w) ret3 = min(ret3, dp[(i - 1) % 4][(i - 1) % 4] + 1);

            sum = board[(i - 1) % 4][0] + board[(i - 2) % 4][0];
            if (sum <= w) ret3 = min(ret3, dp[(i - 2) % 4][i % 4] + 1);

            sum = board[(i - 1) % 4][1] + board[(i - 2) % 4][1];
            if (sum <= w) ret3 = min(ret3, dp[i % 4][(i - 2) % 4] + 1);
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}