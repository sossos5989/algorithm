#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long L = 2000000001;
long long n, m;

int z;

long long optimize() {
    if (z >= 99) return -1;
    long long lo = 0, hi = L;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if ((m + mid) * 100 / (n + mid) == z)
            lo = mid;
        else
            hi = mid;
    }
    return hi;
}

int main() {
    fastIO;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        z = m * 100 / n;
        cout << optimize() << endl;
    }
    return 0;
}