#include <algorithm>
#include <iostream>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<pair<int, int>> adj[100001];

int ans = 0;
int dfs(int node) {
    int first = 0, second = 0;
    for (auto &edge : adj[node]) {
        int cand = dfs(edge.first) + edge.second;

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
    int n, u, v, w;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dfs(1);
    cout << ans;
    return 0;
}
