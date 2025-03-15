#include <iostream>
#include <queue>
using namespace std;

int M, N, box[1001][1001], visited[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N;
    queue<pair<int, int>> q;

    // 입력 받기
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> box[y][x];
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (box[y][x] == 1) {
                q.push({y, x});
                visited[y][x] = 1;
            }
        }
    }

    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (box[ny][nx] == 0 && visited[ny][nx] == 0) {
                box[ny][nx] = 1;
                visited[ny][nx] = visited[cur.first][cur.second] + 1;
                q.push({ny, nx});
            }
        }
    }

    int days = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (box[y][x] == 0) {
                cout << -1 << "\n";
                return 0;
            }
            days = max(days, visited[y][x]);
        }
    }

    cout << days - 1 << "\n";
    return 0;
}
