#include <iostream>
#include <queue>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, a, b;
double c;

int main() {
    fastIO;
    int C;
    cin >> C;
    cout.precision(10);
    cout << fixed;
    while (C--) {
        cin >> n >> m;

        vector<vector<pair<double, int>>> adj(n); // max-heap

        while (m--) {
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(c, b));
            adj[b].push_back(make_pair(c, a));
        }

        vector<double> distance(n, 1e100);
        priority_queue<pair<double, int>, vector<pair<double, int>>,
                       greater<pair<double, int>>>
            q;

        q.push(make_pair(1.0, 0));

        while (!q.empty()) {
            pair<double, int> head = q.top();
            q.pop();
            if (distance[head.second] < head.first) continue;

            for (auto &i : adj[head.second]) {
                double new_dist = head.first * i.first;
                int new_node = i.second;
                if (distance[new_node] > new_dist) {
                    distance[new_node] = new_dist;
                    q.push(make_pair(new_dist, new_node));
                }
            }
        }
        cout << distance[n - 1] << "\n";
    }
    return 0;
}