#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int mod = 1234567891;
long l, sum, pow = 1;
string s;

int main() {
    fastIO;
    cin >> l >> s;
    for (int i = 0; i < l; i++) {
        sum += (s[i] - 96) * pow;
        sum %= mod;
        pow = (pow * 31) % mod;
    }
    cout << sum;
    return 0;
}