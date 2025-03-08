#include <algorithm>
#include <iostream>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int INF = 1e9;
int v, e;
pair<int, int> crackdown[501];
int adj[501][501];
int C[501][501];

int main() {
    fastIO;
    cin >> v >> e;
    for (int i = 1; i <= v; i++) {
        cin >> crackdown[i].first;
        crackdown[i].second = i;
    }
    sort(crackdown + 1, crackdown + v + 1);
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i != j) {
                adj[i][j] = INF;
                C[i][j] = INF;
            }
        }
    }
    int a, b, c;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                int here = crackdown[k].second;
                adj[i][j] = min(adj[i][j], adj[i][here] + adj[here][j]);
                C[i][j] = min(C[i][j],
                              adj[i][here] + adj[here][j] + crackdown[k].first);
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int s, t;
        cin >> s >> t;
        cout << C[s][t] << "\n";
    }
    return 0;
}