#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int INF = 1e9;
int v, m, n, adj[200][200];

int main() {
    fastIO;
    int T;
    cin >> T;
    while (T--) {
        cin >> v >> m >> n;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (i != j)
                    adj[i][j] = INF;
                else
                    adj[i][j] = 0;
            }
        }

        int a, b, c;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            adj[a][b] = adj[b][a] = min(c, adj[a][b]);
        }

        // Floyd 수행
        for (int k = 0; k < v; k++) {
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        int count = 0;
        for (int iter = 0; iter < n; iter++) {
            cin >> a >> b >> c;
            if (adj[a][b] <= c) {
                count++;
                continue;
            }
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    int cand = min(adj[i][a] + c + adj[b][j],
                                   adj[i][b] + c + adj[a][j]);
                    if (adj[i][j] > cand) {
                        adj[i][j] = cand;
                    }
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}