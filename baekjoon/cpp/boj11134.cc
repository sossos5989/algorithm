#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int t, n, c;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        cout << (n + c - 1) / c << '\n';
    }
    return 0;
}