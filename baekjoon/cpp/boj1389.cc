#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int INF = 1e9;
int dist[101][101];

int main() {
    fastIO;
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) dist[i][j] = INF;

    while (m--) {
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int ans = -1, count = INF;
    for (int i = 1; i <= n; i++) {
        int cand = 0;
        for (int j = 1; j <= n; j++)
            cand += dist[i][j];
        if (count > cand) {
            count = cand;
            ans = i;
        }
    }

    cout << ans;
    return 0;
} // 플로이드 워셜