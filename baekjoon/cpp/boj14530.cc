#include <cmath>
#include <iostream>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int x, y, dist = 1, ans = 0, plus = 1;
    cin >> x >> y;

    int origin = x;
    while (1) {
        int cur = origin + plus * dist;
        if ((x <= y && y <= cur) || (cur <= y && y <= x)) break;

        ans += abs(cur - x);
        x = cur;

        dist *= 2;
        plus *= -1;
    }
    cout << ans + abs(x - y);
    return 0;
}
