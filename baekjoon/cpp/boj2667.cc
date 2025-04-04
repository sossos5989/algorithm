#include <algorithm>
#include <iostream>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
string cache;
vector<string> list;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool visited[51][51];
int cnt = 0;
void dfs(int x, int y) {
    visited[x][y] = 1;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
        if (list[xx][yy] == '1' && !visited[xx][yy]) dfs(xx, yy);
    }
}

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cache;
        list.push_back(cache);
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && list[i][j] == '1') {
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto &&i : ans) {
        cout << i << "\n";
    }

    return 0;
}