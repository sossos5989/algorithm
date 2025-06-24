#include <iostream>
#include <numeric>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, a, b, parent[500001], r[500001];

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
    cin >> n >> m;

    iota(parent, parent + n, 0);

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        if (find(a) == find(b) && ans == 0)
            ans = i;
        else
            unin(a, b);
    }
    cout << ans;
    return 0;
}