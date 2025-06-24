#include <iostream>
#include <numeric>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, parent[1000001], r[1000001];

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

    iota(parent, parent + n + 1, 0);

    int q, a, b;
    while (m--) {
        cin >> q >> a >> b;
        if (q) {
            cout << (find(a) == find(b) ? "YES\n" : "NO\n");
        } else {
            unin(a, b);
        }
    }

    return 0;
}