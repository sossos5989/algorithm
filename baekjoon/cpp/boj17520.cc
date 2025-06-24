#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, ans = 1;
    cin >> n;
    n = (n + 1) / 2;
    while (n--) {
        ans *= 2;
        ans %= 16769023;
    }
    cout << ans;
    return 0;
}