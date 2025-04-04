#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> adj[200001];

int cnt = 0;
int visited[200001];
void dfs(int parent, int node) {
    visited[node] = 1;
    for (auto &i : adj[node]) {
        if (i == parent) continue;
        if (visited[i] == 2) {

        } else if (visited[i] == 1)
            cnt++;
        else
            dfs(node, i);
    }
    visited[node] = 2;
}

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(-1, i);
    }
    cout << cnt;

    return 0;
}