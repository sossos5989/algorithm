#include <cstring>
#include <iostream>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int adj[101][101];

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;

    memset(adj, 0x3f, sizeof(adj));

    for (int i = 1; i <= n; i++)
        adj[i][i] = 0;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << (adj[i][j] != 0x3f3f3f3f ? adj[i][j] : 0) << ' ';
        cout << '\n';
    }

    return 0;
}