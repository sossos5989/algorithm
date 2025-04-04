#include <iostream>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k, visited[100001];

int main() {
    fastIO;
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while (!q.empty()) {
        int now = q.front();
        if (now == k) break;
        q.pop();
        if (now * 2 <= 100000 && !visited[now * 2]) {
            q.push(now * 2);
            visited[now * 2] = visited[now];
        }
        if (now - 1 >= 0 && !visited[now - 1]) {
            q.push(now - 1);
            visited[now - 1] = visited[now] + 1;
        }
        if (now + 1 <= 100000 && !visited[now + 1]) {
            q.push(now + 1);
            visited[now + 1] = visited[now] + 1;
        }
    }
    cout << visited[k] - 1;
    return 0;
}