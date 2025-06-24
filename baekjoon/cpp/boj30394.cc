#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, x, y, minY = 2 * 1e9, maxY = -2 * 1e9;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        minY = min(minY, y);
        maxY = max(maxY, y);
    }
    cout << maxY - minY;
    return 0;
}