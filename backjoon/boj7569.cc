#include <iostream>
#include <queue>
using namespace std;

int M, N, H, box[100][100][100], visited[100][100][100];

struct Coord {
    int z, y, x;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> H;
    queue<Coord> q;

    // 입력 받기
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> box[z][y][x];
            }
        }
    }

    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (box[z][y][x] == 1) {
                    q.push({z, y, x});
                    visited[z][y][x] = 1;
                }
            }
        }
    }

    int dz[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dx[6] = {0, 0, 0, 0, 1, -1};

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nz = cur.z + dz[i];
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;

            if (box[nz][ny][nx] == 0 && visited[nz][ny][nx] == 0) {
                box[nz][ny][nx] = 1;
                visited[nz][ny][nx] = visited[cur.z][cur.y][cur.x] + 1;
                q.push({nz, ny, nx});
            }
        }
    }

    int days = 0;
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (box[z][y][x] == 0) {
                    cout << -1 << "\n";
                    return 0;
                }
                days = max(days, visited[z][y][x]);
            }
        }
    }

    cout << days - 1 << "\n";
    return 0;
}
