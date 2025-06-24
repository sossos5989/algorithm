#include <iostream>
#include <queue>

using namespace std;

int board[2000][2000];
int visited[2000][2000];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = 1;

    while (!q.empty()) {
        auto head = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int xx = head.first + dx[k];
            int yy = head.second + dy[k];

            if (xx < 1 || xx > n || yy < 1 || yy > n) {
                continue;
            }

            if (visited[xx][yy]) {
                continue;
            }

            if (board[xx][yy] == (visited[head.first][head.second] % 4) + 1) {
                visited[xx][yy] = visited[head.first][head.second] + 1;
                q.push({xx, yy});
            }
        }
    }

    cout << visited[r][c] - 1;

    return 0;
}
