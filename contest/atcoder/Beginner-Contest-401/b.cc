#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, k;
    long long digit = 1, ans = 1, input;
    cin >> n >> k;

    while (k--) {
        digit *= 10;
    }

    for (int i = 0; i < n; i++) {
        cin >> input;
        if (ans > (digit - 1) / input)
            ans = 1;
        else
            ans *= input;
    }

    cout << ans;
    return 0;
}