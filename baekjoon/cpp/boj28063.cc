#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, x, y, ans = 4;
    cin >> n >> x >> y;
    if (n == 1)
        ans = 0;
    else {
        if (x == 1 || x == n) ans--;
        if (y == 1 || y == n) ans--;
    }
    cout << ans;
    return 0;
}