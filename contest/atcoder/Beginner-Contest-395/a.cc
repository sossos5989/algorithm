#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, max, cache;
    bool b = true;
    cin >> n >> max;
    for (int i = 1; i < n; i++) {
        cin >> cache;
        if (max >= cache) b = false;
        max = cache;
    }
    cout << (b ? "YES" : "NO");
    return 0;
}