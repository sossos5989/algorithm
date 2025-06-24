#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int e, f, c;
    cin >> e >> f >> c;
    e += f;
    int ans = 0;
    while (e >= c) {
        int cache = e / c;
        ans += cache;
        e %= c;
        e += cache;
    }
    cout << ans;
    return 0;
}