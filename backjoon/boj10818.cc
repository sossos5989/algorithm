#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, cache, lo = 1000000, hi = -1000000;

int main() {
    fastIO;
    cin >> n;
    while (n--) {
        cin >> cache;
        lo = min(lo, cache);
        hi = max(hi, cache);
    }
    cout << lo << " " << hi;
    return 0;
}