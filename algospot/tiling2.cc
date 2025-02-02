#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
int cache[1001];

int function(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int& ret = cache[n];
    if(ret != -1) return ret;

    return ret = (function(n-1) + function(n-2)) % MOD;
}
int main() {
    int repeat;
    cin >> repeat;
    while (repeat-- > 0) {
        memset(cache, -1, sizeof(cache));
        int input;
        cin >> input;
        cout << function(input) << "\n";
    }
    return 0;
}
