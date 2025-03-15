#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, k, x, y;
int coord[51][51];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool visited[51][51];
void dfs(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= m || xx < 0 || yy >= n || yy < 0) continue;
        if (!visited[xx][yy] && coord[xx][yy]) {
            dfs(xx, yy);
        }
    }
}

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        memset(coord, 0, sizeof(coord));
        memset(visited, 0, sizeof(visited));
        cin >> m >> n >> k;
        while (k--) {
            cin >> x >> y;
            coord[x][y] = 1;
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (coord[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}