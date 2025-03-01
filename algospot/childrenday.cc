#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string d;
int n, m, visited[20000], parent[20000];

inline int mod(int x, int y) {
    int ret = (x * 10 + y) % n;
    if (x * 10 + y >= n) ret += n;
    return ret;
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> d >> n >> m;
        vector<int> numList;
        for (int i = 0; i < d.size(); i++) {
            numList.push_back(d[i] - '0');
        }
        sort(numList.begin(), numList.end());

        memset(visited, -1, sizeof(int) * 2 * n);
        memset(parent, -1, sizeof(int) * 2 * n);

        queue<int> q;
        q.push(0);
        visited[0] = 1;
        parent[0] = 0;
        while (!q.empty()) {
            int here = q.front();
            q.pop();
            for (int &i : numList) {
                int next = mod(here, i);
                if (visited[next] == -1) {
                    q.push(next);
                    visited[next] = i;
                    parent[next] = here;
                }
            }
        }

        int ptr = n + m;
        string answer = "";

        if (parent[ptr] == -1) {
            answer = "IMPOSSIBLE";
        } else {
            while (parent[ptr] != ptr) {
                answer += char(visited[ptr] + '0');
                ptr = parent[ptr];
            }
            reverse(answer.begin(), answer.end());
        }

        cout << answer << "\n";
    }
    return 0;
}