#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
string input;
int adj[26][26];
int inDegree[26], outDegree[26];
vector<string> graph[26][26];
vector<int> path;

void eulerTour(int u) {
    for (int v = 0; v < 26; v++) {
        while (adj[u][v] > 0) {
            adj[u][v]--;
            // outDegree[u]--;
            // inDegree[v]--;
            eulerTour(v);
        }
    }
    path.push_back(u);
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        memset(adj, 0, sizeof(adj));
        memset(inDegree, 0, sizeof(inDegree));
        memset(outDegree, 0, sizeof(outDegree));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                graph[i][j].clear();
            }
        }

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> input;
            int u = input[0] - 'a', v = input[input.size() - 1] - 'a';
            graph[u][v].push_back(input);
            adj[u][v]++;
            outDegree[u]++;
            inDegree[v]++;
        }

        bool can = true;
        int source = -1, sink = -1, start = -1;
        for (int i = 0; i < 26; i++) {
            if (outDegree[i] && start == -1) start = i;
            if (outDegree[i] - inDegree[i]) {
                if (outDegree[i] - inDegree[i] == 1 && source == -1) {
                    source = i;
                    continue;
                }
                if (outDegree[i] - inDegree[i] == -1 && sink == -1) {
                    sink = i;
                    continue;
                }
                can = false;
                break;
            }
        }
        source = source != -1 ? source : start;

        path.clear();
        eulerTour(source);

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (adj[i][j] > 0) {
                    can = false;
                    break;
                }
            }
        }

        if (!can) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        for (int i = path.size() - 2; i >= 0; i--) {
            cout << *(graph[path[i + 1]][path[i]].end() - 1) << " ";
            graph[path[i + 1]][path[i]].pop_back();
        }
        cout << "\n";
    }
    return 0;
}