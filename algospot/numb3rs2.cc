#include <bits/stdc++.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int N; cin >> N;
    cout << fixed << setprecision(20);
    while (N--) {
        int n, m, k; cin >> n >> m >> k;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x) adj[i].push_back(j);
        }
        
        vector<double> DP(n, 0); DP[k] = 1;  // 감옥 세팅
        while (m--) {
            vector<double> nDP(n, 0);
            for (int i = 0; i < n; i++) for (int j : adj[i])
                nDP[j] += DP[i] / adj[i].size();
            DP = nDP;
        }
        
        int q; cin >> q;
        while (q--) { int x; cin >> x; cout << DP[x] << ' '; }
        cout << '\n';
    }
}  // 이거 엄청 맘에 든다!, 마르코프 체인
