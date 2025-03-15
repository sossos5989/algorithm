#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, m, psum[100001], i, j;
    cin >> n >> m;
    psum[0] = 0;
    for (int k = 1; k <= n; k++) {
        cin >> i;
        psum[k] = psum[k - 1] + i;
    }
    while (m--) {
        cin >> i >> j;
        cout << psum[j] - psum[i - 1] << "\n";
    }
    return 0;
}