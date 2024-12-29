#include <iostream>
#include <limits> // numeric_limits<double>::infinity() 사용
using namespace std;

static const double INF = numeric_limits<double>::infinity();

int n;
double dist[8][8];
double DP[8][1 << 8];

double tsp(int current, int visited) {
    if (visited == (1 << n) - 1) {
        return 0.0;
    }

    double &ret = DP[current][visited];
    if (ret >= 0.0) {
        return ret;
    }

    ret = INF;
    for (int next = 0; next < n; next++) {
        if (visited & (1 << next))
            continue;
        double cost = dist[current][next] + tsp(next, visited | (1 << next));
        ret = min(ret, cost);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dist[i][j];
            }
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < (1 << 8); j++) {
                DP[i][j] = -1.0;
            }
        }

        double answer = INF;
        for (int start = 0; start < n; start++) {
            answer = min(answer, tsp(start, 1 << start));
        }
        cout.precision(20);
        cout << answer << "\n";
    }
    return 0;
}
