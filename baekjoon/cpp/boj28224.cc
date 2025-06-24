#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, cache, ans = 0;
    cin >> n;
    while (n--) {
        cin >> cache;
        ans += cache;
    }
    cout << ans;
    return 0;
}