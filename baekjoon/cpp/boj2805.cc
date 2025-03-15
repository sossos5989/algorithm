#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, m, lo = 0, hi = 1000000001, h[1000000];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        long sum = 0;
        for (int i = 0; i < n; i++)
            sum += max(h[i] - mid, 0);

        if (sum >= m)
            lo = mid;
        else
            hi = mid;
    }
    cout << lo;
    return 0;
}