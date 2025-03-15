#include <climits>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int k, n, list[10000], l;

int main() {
    fastIO;
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> list[i];
        l = max(l, list[i]);
    }
    long long lo = 1, hi = l;
    while (lo <= hi) {
        long long mid = (long long)(lo + hi) / 2;
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += list[i] / mid;
        }
        if (sum >= n)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << hi;
    return 0;
}
