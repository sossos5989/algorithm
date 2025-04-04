#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> adj[101];
vector<int> weight0Adj[101];
int visited[101];

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 6 && i + j <= 100; j++) {
            adj[i].push_back(i + j);
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        weight0Adj[a].push_back(b);
        adj[a].clear();
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        weight0Adj[a].push_back(b);
        adj[a].clear();
    }

    memset(visited, -1, sizeof(visited));
    queue<int> q;
    q.push(1);
    visited[1] = 0;
    for (int &k : weight0Adj[1]) {
        if (visited[k] == -1) {
            q.push(k);
            visited[k] = 0;
        }
    }

    while (!q.empty()) {
        int head = q.front();
        q.pop();
        for (int &i : adj[head]) {
            if (visited[i] == -1) {
                q.push(i);
                visited[i] = visited[head] + 1;
                for (int &k : weight0Adj[i]) {
                    if (visited[k] == -1) {
                        q.push(k);
                        visited[k] = visited[i];
                    }
                }
            }
        }
    }

    cout << visited[100];
    return 0;
} // weight가 1인 graph, 0인 그래프로 가정해 풀음