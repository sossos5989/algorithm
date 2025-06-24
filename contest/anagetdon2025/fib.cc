#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long c, k;
const long long MOD = 1000000007;
long long fib[5000001];
long long psum[5000001];

int main() {
    fastIO;
    cin >> c >> k;
    fib[1] = 1;
    for (int i = 2; i <= 5000000; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    for (int i = 1; i <= 5000000; i++) {
        psum[i] = (psum[i - 1] + fib[i]) % MOD;
    }

    long long ans = 0;
    for (int i = 2; i <= 2 * k; i += 2) {
        ans += fib[i];
        ans %= MOD;
        ans += c * psum[i - 2];
        ans %= MOD;
    }

    cout << ans;
    return 0;
}