#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, cand;

int main() {
    fastIO;
    cin >> n;
    while (n) {
        cand++;
        int cache = cand, streak = 0, hi = 0;
        while (cache) {
            if (cache % 10 == 6) {
                streak++;
            } else {
                streak = 0;
            }
            hi = max(streak, hi);
            cache /= 10;
        }
        if (hi >= 3) n--;
    }
    cout << cand;
    return 0;
} // 미친 브루트포스 알고리즘, 되긴 하잖아 한잔해~
