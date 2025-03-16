#include <iostream>
#include <math.h>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long function(long long x, long long y) {
    long long xx = x * x, xy = x * y, yy = y * y;
    if (xx / x != x) return -1;
    if (xy / x != y) return -1;
    if (yy / y != y) return -1;
    if (xx + xy + yy - yy - xy != xx) return -1;
    return xx + xy + yy;
}

int main() {
    fastIO;
    long long n;
    cin >> n;

    long long sqrtN = sqrt(n);
    vector<long long> cand;
    cand.push_back(1);
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            cand.push_back(i);
        }
    }

    long long ans1, ans2;
    bool isFound = false;
    for (long long &gap : cand) {
        long long lo = 1, hi = sqrtN;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long x = mid + gap, y = mid;
            long long cand = gap * function(x, y);
            if (cand / gap != function(x, y)) {
                hi = mid - 1;
            } else if (cand < n)
                lo = mid + 1;
            else if (cand > n)
                hi = mid - 1;
            else {
                ans1 = x;
                ans2 = y;
                isFound = true;
                break;
            }
        }
        if (isFound) break;
    }

    if (isFound)
        cout << ans1 << " " << ans2;
    else
        cout << -1;
    return 0;
}