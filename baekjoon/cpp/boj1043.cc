#include <iostream>
#include <queue>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int visited[51];
vector<int> adj[51];

int main() {
    fastIO;
    int n, m, t, c, a;
    queue<int> q;

    cin >> n >> m >> t;

    while (t--) {
        cin >> c;
        q.push(c);
    }

    for (int i = 0; i < m; i++) {
        cin >> t;
        while (t--) {
            cin >> a;
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
    }

    while (!q.empty()) {
        auto head = q.front();
        visited[head] = 1;
        for (auto &&i : adj[head]) {
            if (!visited[i]) {
                q.push(i);
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}