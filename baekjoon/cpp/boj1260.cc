#include <iostream>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, v, a, b, adj[1001][1001];

bool visitedDFS[1001], visitedBFS[1001];
void dfs(int start) {
    cout << start << " ";
    visitedDFS[start] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[start][i] && !visitedDFS[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visitedBFS[start] = 1;
    while (!q.empty()) {
        int here = q.front();
        cout << here << " ";
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (adj[here][i] && !visitedBFS[i]) {
                q.push(i);
                visitedBFS[i] = 1;
            }
        }
    }
}

int main() {
    fastIO;
    cin >> n >> m >> v;
    while (m--) {
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    } // make graph
    dfs(v);
    cout << "\n";
    bfs(v);
    return 0;
}