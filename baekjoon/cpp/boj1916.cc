#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
vector<pair<int, int>> adj[1001];
int dist[1001];

int main() {
    fastIO;
    cin >> n >> m;
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        adj[a].push_back({-c, b});
    }
    cin >> a >> b;

    memset(dist, 0x7f, sizeof(dist));
    dist[a] = 0;

    priority_queue<pair<int, int>> q;
    q.push({0, a});

    while (!q.empty()) {
        auto head = q.top();
        q.pop();

        if (dist[head.second] < -head.first) continue;

        dist[head.second] = -head.first;

        for (auto &i : adj[head.second]) {
            int value = dist[head.second] - i.first;
            if (value < dist[i.second]) {
                dist[i.second] = value;
                q.push({-value, i.second});
            }
        }
    }

    cout << dist[b];
    return 0;
}