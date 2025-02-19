#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, D[1000001] = {0, 0, 1, 1};
    cin >> n;
    for (int i = 4; i <= n; i++) {
        int ret = D[i - 1] + 1;
        if (i % 2 == 0) ret = min(ret, D[i / 2] + 1);
        if (i % 3 == 0) ret = min(ret, D[i / 3] + 1);
        D[i] = ret;
    }
    cout << D[n];
    return 0;
}