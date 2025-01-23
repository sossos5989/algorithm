#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k;
int r[2000], c[2000];

bool decision(double p) {
    vector<double> v;
    for (int i = 0; i < n; i++) {
        v.push_back(p * c[i] - r[i]);
    }
    nth_element(v.begin(), v.begin() + k, v.end(), greater<double>());
    return accumulate(v.begin(), v.begin() + k, 0.0) >= 0;
}

double optimize() {
    double lo = 0.0, hi = 1.0;
    int it = 100;
    while (it--) {
        double mid = (lo + hi) / 2.0;
        if (decision(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main() {
    fastIO;
    int T;
    cin >> T;
    cout << fixed << setprecision(10);
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> r[i] >> c[i];
        }
        cout << fixed << optimize() << endl;
    }
    return 0;
}