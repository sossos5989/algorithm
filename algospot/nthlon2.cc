#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> j;

int dijkstra() {
    int d[401], i;
    priority_queue<pair<int, int>> q;
    for (i = 0; i < 401; i++)
        d[i] = 1e9;
    q.push(make_pair(0, 200));
    bool c = true;
    while (!q.empty()) {
        int h = q.top().second, l = -q.top().first;
        q.pop();
        if (l > d[h]) continue;
        if (c)
            d[200] = 1e9, c = false;
        else if (h == 200)
            return l;
        for (i = 0; i < j.size(); i++) {
            int t = h + j[i].second, n = l + j[i].first;
            if (t < 0 || t > 400) continue;
            if (n < d[t]) d[t] = n, q.push(make_pair(-n, t));
        }
    }
    return -1;
}

int main() {
    int t, m, i, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &m);
        j.clear();
        j.resize(m);
        for (i = 0; i < m; i++)
            scanf("%d%d", &a, &b), j[i] = make_pair(a, a - b);
        int ret = dijkstra();
        if (ret == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ret);
    }
}