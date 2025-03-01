#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, u, v, count, adj[1001][1001];
bool visited[1001];
void dfs(int here) {
    visited[here] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[here][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    fastIO;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    cout << count;
    return 0;
}