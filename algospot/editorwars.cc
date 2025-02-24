#include <iostream>
#include <numeric>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
vector<int> parent, r, enemy, s;

void init() {
    parent.clear();
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    r.assign(n, 0);
    enemy.assign(n, -1);
    s.assign(n, 1);
}

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

int merge(int u, int v) {
    if (u == -1 || v == -1) return max(u, v);
    u = find(u), v = find(v);
    if (u == v) return u;
    if (r[u] > r[v]) swap(u, v);
    if (r[u] == r[v]) r[v]++;
    parent[u] = v;
    s[v] += s[u];
    return v;
}

bool ack(int u, int v) {
    u = find(u), v = find(v);
    if (enemy[u] == v) return false;
    int a = merge(u, v), b = merge(enemy[u], enemy[v]);
    enemy[a] = b;
    if (b != -1) enemy[b] = a;
    return true;
}

bool dis(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    int a = merge(u, enemy[v]), b = merge(enemy[u], v);
    enemy[a] = b;
    enemy[b] = a;
    return true;
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n >> m;
        init();
        string cache;
        int a, b, failedIndex = -1;
        bool fail = true;
        for (int i = 1; i <= m; i++) {
            cin >> cache >> a >> b;
            if (cache[0] == 'A')
                fail = ack(a, b);
            else
                fail = dis(a, b);
            if (!fail && failedIndex == -1) failedIndex = i;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                int e = enemy[i];
                if (e > i) continue;
                int mySize = s[i];
                int enemySize = e == -1 ? 0 : s[e];
                ret += max(mySize, enemySize);
            }
        }
        if (failedIndex != -1)
            cout << "CONTRADICTION AT " << failedIndex << "\n";
        else
            cout << "MAX PARTY SIZE IS " << ret << "\n";
    }
    return 0;
}