#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, m, board[502][502];
    int psum[502][502];
    vector<pair<int, int>> block_list = {
        {1, 4}, {4, 1}, {2, 2}, {3, 2}, {2, 3}};
    pair<pair<int, int>, pair<int, int>> rm2Block[8] = {
        {{0, 0}, {0, -1}},    {{0, -1}, {0, -2}}, {{-1, 0}, {-1, -1}},
        {{-1, -1}, {-1, -2}}, {{0, 0}, {0, -2}},  {{-1, 0}, {-1, -2}},
        {{0, 0}, {-1, -2}},   {{-1, 0}, {0, -2}}};

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j]; // 1-based index
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            psum[i][j] = psum[i][j - 1] + psum[i - 1][j] + board[i][j] -
                         psum[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int step = 0; step < 5; step++) {
        int dx = block_list[step].first, dy = block_list[step].second;
        for (int i = 0; i + dx <= n; i++) {
            for (int j = 0; j + dy <= m; j++) {
                int cand = psum[i + dx][j + dy] - psum[i][j + dy] -
                           psum[i + dx][j] + psum[i][j];
                if (dx == 3 || dy == 3) {
                    for (int k = 0; k < 8; k++) {
                        pair<int, int> cd1 = rm2Block[k].first;
                        pair<int, int> cd2 = rm2Block[k].second;
                        if (dx == 3) {
                            swap(cd1.first, cd1.second);
                            swap(cd2.first, cd2.second);
                        }
                        ans = max(
                            ans,
                            cand -
                                board[i + dx + cd1.first][j + dy + cd1.second] -
                                board[i + dx + cd2.first][j + dy + cd2.second]);
                    }
                } else {
                    ans = max(ans, cand);
                }
            }
        }
    }
    cout << ans;
    return 0;
}