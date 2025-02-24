#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int g, h;
bool adj[1000][1000]; // 무향 그래프

int camera;
bool visited[1000]; // 0: 방문 x, 1:방문 o
int dfs(int here) {
    visited[here] = true;
    bool unwatched = false, installed = false;
    for (int i = 0; i < g; i++) {
        if (adj[here][i] && !visited[i]) {
            int cand = dfs(i);
            if (cand == 0)
                unwatched = true;
            else if (cand == 2)
                installed = true;
        }
    }
    if (unwatched) {
        ++camera;
        return 2;
    }
    if (installed) return 1;
    return 0;
} // 0: 카메라를 설치 안 함, 1: 자식 노드가 설치되어있어서 설치 x
// 2: 카메라 설치 해야 함

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        memset(adj, 0, sizeof(adj));
        cin >> g >> h;
        int a, b;
        while (h--) {
            cin >> a >> b;
            adj[a][b] = 1;
            adj[b][a] = 1;
        }

        memset(visited, 0, sizeof(visited));
        camera = 0;
        for (int i = 0; i < g; i++) {
            if (!visited[i] && dfs(i) == 0) {
                ++camera;
            }
        }
        cout << camera << "\n";
    }
    return 0;
}