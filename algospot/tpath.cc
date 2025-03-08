#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int INF = 1e9;
int n, m;
vector<pair<int, pair<int, int>>> edge;

int parent[2000], r[2000];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (r[x] > r[y])
        parent[y] = x;
    else {
        parent[x] = y;
        if (r[x] == r[y]) r[y]++;
    }
}

int main() {
    fastIO;
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> m;
        edge.clear();
        int a, b, c;
        while (m--) {
            cin >> a >> b >> c;
            edge.push_back(make_pair(c, make_pair(b, a)));
        }

        sort(edge.begin(), edge.end());

        int answer = INF;
        for (int i = 0; i < edge.size(); i++) {
            iota(parent, parent + n, 0);
            memset(r, 0, n * sizeof(r[0]));
            int min = INF;
            int lo = edge[i].first;
            for (int j = i; j < edge.size(); j++) {
                merge(edge[j].second.first, edge[j].second.second);
                if (find(0) == find(n - 1)) {
                    min = edge[j].first - lo;
                    break;
                }
            }
            answer = answer < min ? answer : min;
        }
        cout << answer << "\n";
    }
    return 0;
}