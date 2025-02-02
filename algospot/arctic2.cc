#include <iostream>
#include <math.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const double MAX = 1500;
int n;
pair<double, double> coord[100];

bool visit[100];
double dist[100];

void init() {
    for (int i = 0; i < n; i++) {
        visit[i] = false;
        dist[i] = MAX;
    }
}

// 연결 그래프인지 확인해야함 ㅇㅇ; 수정할것
void solution() {
    dist[0] = 0.0;
    for (int step = 0; step < n; step++) {
        int u = -1;
        double minDist = MAX;
        for (int i = 0; i < n; i++) {
            if (!visit[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visit[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visit[v]) {
                double dx = coord[u].first - coord[v].first;
                double dy = coord[u].second - coord[v].second;
                double d = sqrt(dx * dx + dy * dy);
                if (d < dist[v]) {
                    dist[v] = d;
                }
            }
        }
    }
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
        init();
        solution();
        double result = 0;
        for (int i = 1; i < n; i++) {
            result = max(result, dist[i]);
        }
        printf("%.2lf\n", result);
    }
    return 0;
}
