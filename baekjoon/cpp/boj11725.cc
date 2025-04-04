#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, a, b;
vector<int> adj[100001];
int answer[100001];

void dfs(int prev, int now) {
    for (auto &i : adj[now]) {
        if (i == prev) continue;
        answer[i] = now;
        dfs(now, i);
    }
}

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    for (int i = 2; i <= n; i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}