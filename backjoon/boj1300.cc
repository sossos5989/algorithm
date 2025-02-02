#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long n, k;

bool decision(long long value) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += min(value / i, n);
    }
    return count >= k;
}

long long optimize() {
    int lo = 0, hi = n * n + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (decision(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main() {
    fastIO;
    cin >> n >> k;
    cout << optimize() << endl;
    return 0;
}
