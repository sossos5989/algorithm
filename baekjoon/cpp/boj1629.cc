#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int a, b, c;

long long times(long long k) {
    if (k == 1) return a % c;
    long long ret = times(k / 2);
    ret *= ret;
    ret %= c;
    if (k % 2 == 1) {
        ret *= times(1);
        ret %= c;
    }
    return ret;
}

int main() {
    fastIO;
    cin >> a >> b >> c;
    cout << times(b);
    return 0;
}