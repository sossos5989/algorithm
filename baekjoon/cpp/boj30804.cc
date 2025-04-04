#include <cstring>
#include <iostream>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, list[200001];
int counter[10];

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    int lo = 0, hi = 0, diff = 1, ans = 0;
    counter[list[0]]++;
    while (lo < n && hi < n) {
        while (diff <= 2 && hi < n - 1) {
            hi++;
            if (!counter[list[hi]]) diff++;
            counter[list[hi]]++;
            if (diff > 2) {
                counter[list[hi]]--;
                hi--, diff--;
                break;
            }
        }
        ans = max(ans, hi - lo + 1);
        counter[list[lo]]--;
        if (counter[list[lo]] == 0) diff--;
        lo++;
    } // 어으 드러워

    cout << ans;
    return 0;
}