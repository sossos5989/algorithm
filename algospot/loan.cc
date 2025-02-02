#include <iostream>
#include <math.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

double n, p;
int m;

bool decision(double c) {
    double ret = n;
    for (int i = 0; i < m; i++) {
        ret *= 1.0 + (p / 1200.0);
        ret -= c;
    }
    return ret <= 0;
}

// bool decision(double c) {
//     double cache = pow(1.0 + (p / 1200.0), m);
//     double ret = n * cache - 1200 * c / p * (cache - 1);
//     return ret <= 0;
// }

double optimize() {
    double lo = 0, hi = n * (1.0 + (p / 1200.0));
    int it = 100;
    while (it--) {
        double mid = (lo + hi) / 2.00;
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
    cout.precision(15);
    while (T--) {
        cin >> n >> m >> p;
        cout << optimize() << endl;
    }
    return 0;
}