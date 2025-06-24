#include <iostream>
#include <queue>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int used[27], inDegree[27];
vector<int> adj[27];

int main() {
    fastIO;
    int n;
    string prev, now;
    cin >> n >> prev;
    for (int i = 0; i < prev.size(); i++)
        used[prev[i] - 'a'] = 1;
    used[26] = 1;

    for (int i = 0; i < 26; i++) {
        adj[26].push_back(i);
        inDegree[i]++;
    }

    while (--n) {
        cin >> now;

        for (int i = 0; i < max(prev.size(), now.size()); i++) {
            int pIdx = i < prev.size() ? prev[i] - 'a' : 26;
            int nIdx = i < now.size() ? now[i] - 'a' : 26;
            if (pIdx != nIdx) {
                if (pIdx != 26) {
                    adj[pIdx].push_back(nIdx);
                    inDegree[nIdx]++;
                }
                break;
            }
        }

        prev = now;

        for (int i = 0; i < prev.size(); i++)
            used[prev[i] - 'a'] = 1;
    }

    // Khan's algorithm 변형
    int alphabetCounter = 0;
    for (int i = 0; i < 27; i++)
        if (used[i]) alphabetCounter++;

    string ans;
    queue<int> q;
    if (inDegree[26] == 0) {
        q.push(26);
        used[26] = 0;
    }

    int flag = 0;
    while (!q.empty()) {
        if (q.size() > 1) flag = 1;

        int u = q.front();
        q.pop();
        alphabetCounter--;

        if (u != 26) ans += char(u + 'a');

        for (int v : adj[u]) {
            if (--inDegree[v] == 0 && used[v]) {
                q.push(v);
                used[v] = 0;
            }
        }
    }

    if (alphabetCounter)
        ans = "!";
    else if (flag)
        ans = "?";
    cout << ans;
    return 0;
}

// 원래 DFS기반 topological sort를 구현하려고 했지만.
// 찾아보니 BFS기반 Khan's algorithm을 이용해 구현한다.