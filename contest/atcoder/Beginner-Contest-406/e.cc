#include <iostream>
#include <queue>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> adj[200001];
int visited[200001], ans[200001];
int main() {
    fastIO;
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;
    // 깊이 바뀔 때 정산
    int depth = 1, lo = 1000000;
    while (!q.empty()) {
        int head = q.front();
        q.pop();

        if (depth != visited[head]) {
            depth = visited[head];

            lo = 1000000;
        }
        
        lo = min(lo, head);
        for (auto &i : adj[head]) {
            if (visited[i] == 0) {
                q.push(i);
                visited[i] = visited[head] + 1;
            }
        }
    }

    return 0;
}