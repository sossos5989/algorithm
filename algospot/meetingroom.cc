#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
pair<int, int> meeting[200];
vector<vector<int>> adj; // 간선

int sccCounter, vertexCounter;
int visited[200], sccId[200];
stack<int> st;
int dfs(int node) {
    int ret = visited[node] = vertexCounter++;
    st.push(node);
    for (int &i : adj[node]) {
        if (visited[i] == -1)
            ret = min(ret, dfs(i));
        else if (sccId[i] == -1)
            ret = min(ret, visited[i]);
    }
    if (ret == visited[node]) {
        while (true) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if (t == node) break;
        }
        sccCounter++;
    }
    return ret;
}

void tarjanSCC() {
    sccCounter = vertexCounter = 0;
    memset(visited, -1, sizeof(visited));
    memset(sccId, -1, sizeof(sccId));
    for (int i = 0; i < 2 * n; i++) {
        if (visited[i] == -1) dfs(i);
    }
}

vector<int> value;
bool solve2SAT() {
    // 각 노드에 대해 sccId를 구한다.
    tarjanSCC();

    // 이 문제가 성립가능한지 검사한다.
    for (int i = 0; i < n; i++) {
        if (sccId[2 * i] == sccId[2 * i + 1]) return false;
    }

    // tarjan의 sccId의 역순으로 정렬하면, 위상정렬이다.
    vector<pair<int, int>> order;
    for (int i = 0; i < 2 * n; i++) {
        order.push_back(make_pair(-sccId[i], i));
    }
    sort(order.begin(), order.end());

    // 주간 회의를 뽑을지, 월간 회의를 뽑을 지 결정한다.
    value.assign(n, -1);
    for (auto &kv : order) {
        int lit = kv.second;
        int var = lit / 2;
        if (value[var] != -1) continue;
        value[var] = (lit % 2 == 0);
    }
    return true;
}

bool disjoint(const pair<int, int> &a, const pair<int, int> &b) {
    return b.second <= a.first || a.second <= b.first;
}

int main() {
    fastIO;
    int T, a, b;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a >> b;
            meeting[i] = make_pair(a, b);
        }

        adj.assign(2 * n, {});
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!disjoint(meeting[2 * i], meeting[2 * j])) {
                    adj[2 * i].push_back(2 * j + 1);
                    adj[2 * j].push_back(2 * i + 1);
                }
                if (!disjoint(meeting[2 * i], meeting[2 * j + 1])) {
                    adj[2 * i].push_back(2 * j);
                    adj[2 * j + 1].push_back(2 * i + 1);
                }
                if (!disjoint(meeting[2 * i + 1], meeting[2 * j])) {
                    adj[2 * i + 1].push_back(2 * j + 1);
                    adj[2 * j].push_back(2 * i);
                }
                if (!disjoint(meeting[2 * i + 1], meeting[2 * j + 1])) {
                    adj[2 * i + 1].push_back(2 * j);
                    adj[2 * j + 1].push_back(2 * i);
                }
            }
        }

        if (solve2SAT()) {
            cout << "POSSIBLE\n";
            for (int i = 0; i < n; i++) {
                int chosen = 2 * i + (value[i] == 1);
                cout << meeting[chosen].first << " " << meeting[chosen].second
                     << "\n";
            }
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
