#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
int cache[1001];

int function(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int& ret = cache[n];
    if(ret != -1) return ret;

    return ret = (function(n-1) + function(n-2)) % MOD;
}

int asymtiling1(int n) {
    if (n == 1) return 0;
    if (n == 2) return 0;

    if (n % 2 == 1) return (function(n) - function(n / 2)) % MOD;
    return (function(n) - function(n / 2) - function((n / 2) - 1)) % MOD;
}  // 전체 - 대칭 타일링 개수 count

int cache2[101];

int asymtiling2(int n) {
    if (n <= 2) return 0;  // 예외 처리 및 base case

    int& ret = cache2[n];
    if (ret != -1) return ret;

    ret = asymtiling2(n - 2) % MOD;
    ret = (ret + asymtiling2(n - 4)) % MOD;
    ret = (ret + function(n - 3)) % MOD;
    ret = (ret + function(n - 3)) % MOD;
    return ret;
}  // 비대칭 타일링 개수 count

int main() {
    int repeat;
    cin >> repeat;
    while (repeat-- > 0) {
        memset(cache, -1, sizeof(cache));
        memset(cache2, -1, sizeof(cache2));
        int input;
        cin >> input;
        cout << asymtiling2(input) << "\n";
    } 
    return 0;
}
