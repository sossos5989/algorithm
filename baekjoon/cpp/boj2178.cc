#include <iostream>
#include <queue>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int visited[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty()) {
        auto ptr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = ptr.first + dx[i];
            int yy = ptr.second + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if (visited[xx][yy] || board[xx][yy] == '0') continue;
            q.push({xx, yy});
            visited[xx][yy] = visited[ptr.first][ptr.second] + 1;
        }
    }
    cout << visited[n - 1][m - 1];
    return 0;
}