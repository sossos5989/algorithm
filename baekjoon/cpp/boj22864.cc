#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int pirodo = 0, ans = 0;
    for (int iter = 0; iter < 24; iter++) {
        if (pirodo + a > m)
            pirodo = max(0, pirodo - c);
        else {
            ans += b;
            pirodo += a;
        }
    }
    cout << ans;
    return 0;
}