#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

pair<int, int> point[500];
double adj[500][500];
vector<pair<double, pair<int, int>>> edge_list; // weight, edge

int parent[500], r[500];
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
    cout.precision(10);
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            cin >> point[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> point[i].second;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                double dx = point[i].first - point[j].first;
                double dy = point[i].second - point[j].second;
                double dist = sqrt(dx * dx + dy * dy);
                adj[i][j] = dist;
            }
        }

        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a][b] = adj[b][a] = 0.0;
        }

        edge_list.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                double dist = adj[i][j];
                edge_list.push_back(make_pair(dist, make_pair(i, j)));
            }
        }
        sort(edge_list.begin(), edge_list.end());

        memset(r, 0, n * sizeof(r[0]));
        iota(parent, parent + n, 0);
        double count = 0;
        for (int i = 0; i < edge_list.size(); i++) {
            auto it = edge_list[i];
            int v = it.second.first, u = it.second.second;
            if (find(v) == find(u))
                continue;
            else {
                merge(v, u);
                count += it.first;
            }
        } // using Kruscal's algorithm

        cout << fixed << count << "\n";
    }
    return 0;
}