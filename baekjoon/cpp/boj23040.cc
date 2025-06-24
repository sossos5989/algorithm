#include <iostream>
#include <queue>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, u, v;
vector<int> adj[100001];

// int find(int x) {
//     if (parent[x] == x) return x;
//     return parent[x] = find(parent[x]);
// }

// void unin(int u, int v) {
//     int uu = find(u), vv = find(v);
//     if (r[uu] > r[vv]) {
//         parent[vv] = uu;
//     } else if (r[uu] < r[vv]) {
//         parent[uu] = vv;
//     } else {
//         parent[vv] = uu;
//         r[uu]++;
//     }
// }

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string s;
    cin >> s;

    queue<int> q;

    q.push(1) return 0;
}