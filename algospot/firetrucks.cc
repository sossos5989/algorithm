#include <iostream>
#include <queue>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        int v, e, n, m; // vertex, edge, 화재 장소, 소방서
        cin >> v >> e >> n >> m;

        vector<pair<int, int>> adj[1001]; // first = weight, second = next
        vector<int> fire;
        vector<int> station;
        int a, b, t, input, distance[1001], sum = 0;

        for (int i = 0; i < e; i++) {
            cin >> a >> b >> t;
            adj[a].push_back(make_pair(-t, b));
            adj[b].push_back(make_pair(-t, a));
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            fire.push_back(input);
        }
        for (int i = 0; i < m; i++) {
            cin >> input;
            station.push_back(input);
        }

        for (int i = 1; i <= v; i++) {
            distance[i] = -1e9;
        }

        priority_queue<pair<int, int>> q;
        for (int &i : station) {
            q.push(make_pair(0, i));
            distance[i] = 0;
        }

        while (!q.empty()) {
            int here = q.top().second;
            int weight = q.top().first;
            q.pop();
            if (distance[here] > weight) continue;
            for (auto &i : adj[here]) {
                int there = i.second;
                int new_weight = i.first + weight;
                if (new_weight > distance[there]) {
                    q.push(make_pair(new_weight, there));
                    distance[there] = new_weight;
                }
            }
        }

        for (int &i : fire) {
            sum += distance[i];
        }

        cout << -sum << "\n";
    }
    return 0;
}