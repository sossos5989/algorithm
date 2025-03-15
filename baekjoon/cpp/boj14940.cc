#include <iostream>
#include <queue>
#include <string>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, m, list[1000][1000], length[1000][1000];
    pair<int, int> start;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> list[i][j];
            if (list[i][j] == 2) start = {i, j};
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            length[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    length[start.first][start.second] = 0;
    while (!q.empty()) {
        auto cache = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = cache.first + dx[i];
            int new_y = cache.second + dy[i];

            if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m) continue;
            if (length[new_x][new_y] != -1) continue;
            if (list[new_x][new_y] == 0) continue;
            q.push({new_x, new_y});
            length[new_x][new_y] = length[cache.first][cache.second] + 1;
        }
    }

    string answer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int &cand = length[i][j];
            if (list[i][j] == 0 && cand == -1)
                answer += "0 ";
            else
                answer += to_string(cand) + " ";
        }
        answer += "\n";
    }
    cout << answer;
    return 0;
}