#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int v, e, parent[10001], r[10001];
vector<pair<int, pair<int, int>>> adj;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unin(int u, int v) {
    int uu = find(u), vv = find(v);
    if (r[uu] > r[vv]) {
        parent[vv] = uu;
    } else if (r[uu] < r[vv]) {
        parent[uu] = vv;
    } else {
        parent[vv] = uu;
        r[uu]++;
    }
}

int main() {
    fastIO;
    cin >> v >> e;

    iota(parent + 1, parent + v + 1, 1);

    int a, b, c;
    while (e--) {
        cin >> a >> b >> c;
        adj.push_back({c, {a, b}});
    }

    sort(adj.begin(), adj.end());

    int ans = 0;
    for (auto &[w, uv] : adj) {
        auto [u, v] = uv;
        if (find(u) != find(v)) {
            unin(u, v);
            ans += w;
        }
    } // 이건 신기술이네
    cout << ans;
    return 0;
}