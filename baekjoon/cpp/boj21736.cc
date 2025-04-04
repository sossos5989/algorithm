#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
vector<string> input;

bool visited[600][600];
void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m || input[x][y] == 'X') return;

    visited[x][y] = 1;
    if (!visited[x + 1][y]) dfs(x + 1, y);
    if (!visited[x - 1][y]) dfs(x - 1, y);
    if (!visited[x][y + 1]) dfs(x, y + 1);
    if (!visited[x][y - 1]) dfs(x, y - 1);
}

int main() {
    fastIO;
    cin >> n >> m;
    input.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (input[i][j] == 'I') {
                start = {i, j};
                break;
            }
        }
    }

    dfs(start.first, start.second);

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (input[i][j] == 'P' && visited[i][j]) count++;
        }
    }

    if (count == 0)
        cout << "TT";
    else
        cout << count;
    return 0;
}