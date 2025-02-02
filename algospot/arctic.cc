#include <iostream>
#include <queue>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
pair<double, double> coord[100];

// 연결 그래프인지 확인해야함 ㅇㅇ; 수정할것
bool decision(double gap) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                double dx = coord[u].first - coord[v].first;
                double dy = coord[u].second - coord[v].second;
                double dist2 = dx * dx + dy * dy;
                if (dist2 <= gap * gap) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) return false;
    }

    return true;
}

double optimize() {
    double lo = 0, hi = 1000;
    int it = 1000;
    while (it--) {
        double mid = (lo + hi) / 2.0;
        if (decision(mid))
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}

int main() {
    fastIO;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> coord[i].first >> coord[i].second;
        }

        printf("%.2f\n", optimize());
    }
    return 0;
}