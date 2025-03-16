#include <cstring>
#include <iostream>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int adj[101][101];
int visited[101][101];

int main() {
    fastIO;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int head = q.front();
            q.pop();
            for (int j = 0; j < n; j++) {
                if (adj[head][j] && !visited[i][j]) {
                    q.push(j);
                    visited[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}