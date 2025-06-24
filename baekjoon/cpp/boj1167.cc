#include <algorithm>
#include <iostream>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<pair<int, int>> adj[100001];

int ans = 0;
int dfs(int node, int parent) {
    int first = 0, second = 0;
    for (auto &edge : adj[node]) {
        if (edge.first == parent) continue;

        int cand = dfs(edge.first, node) + edge.second;

        if (cand > first) {
            second = first;
            first = cand;
        } else if (cand > second) {
            second = cand;
        }
    }

    ans = max(ans, first + second);
    return first;
}

int main() {
    fastIO;
    int n, node, v, w;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> node;
        while (true) {
            cin >> v;
            if (v == -1) break;
            cin >> w;
            adj[node].push_back({v, w});
        }
    }

    dfs(1, -1);
    cout << ans;
    return 0;
}
