#include <iostream>
#include <queue>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
vector<pair<int, int>> adj[1001];
bool visited[1001];

int main() {
    fastIO;
    cin >> n >> m;
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    // prim algorithm
    int cnt = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;

    for (auto &i : adj[1]) {
        q.push(i);
    }
    visited[1] = true;
    while (!q.empty()) {
        auto head = q.top();
        q.pop();
        if (visited[head.second]) continue;
        visited[head.second] = 1;
        cnt += head.first;
        for (auto &i : adj[head.second]) {
            if (!visited[i.second]) q.push(i);
        }
    }
    cout << cnt;
    return 0;
}