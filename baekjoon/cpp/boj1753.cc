#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<pair<int, int>> adj[20001];

int dist[20001];
int main() {
    fastIO;
    int n, m, start;
    cin >> n >> m >> start;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    memset(dist, 0x7f, sizeof(int) * (n + 1));

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto head = pq.top();
        pq.pop();

        if (dist[head.second] < head.first) continue;

        for (auto &i : adj[head.second]) {
            int cand = i.first + dist[head.second];
            if (dist[i.second] > cand) {
                dist[i.second] = cand;
                pq.push({cand, i.second});
            }
        }
    }

    for (int i = 1; i <= n; i++)
        if (dist[i] == 2139062143)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';

    return 0;
}