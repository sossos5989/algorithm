#include <cmath>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
double list[200];

bool decision(double gap) {
    double limit = -1;
    int installed = 0;
    for (int i = 0; i < m; i++) {
        if (limit <= list[i]) {
            installed++;
            limit = list[i] + gap;
        }
    }
    return installed >= n;
}

double optimize() {
    double lo = 0, hi = 241;
    int it = 100;
    while (it--) {
        double mid = (lo + hi) / 2.0;
        if (decision(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
    fastIO;
    int T;
    cin >> T;
    cout.precision(2);
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> list[i];
        }
        cout << fixed << round(optimize() * 100.0) / 100.0 << endl;
    }
    return 0;
}