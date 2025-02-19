#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;

int DP[1001];
int function(int k) {
    if (k <= 1) return k;
    if (k == 2) return 3;
    if (DP[k] != -1) return DP[k];
    return DP[k] = (function(k - 1) + 2 * function(k - 2)) % 10007;
}

int main() {
    fastIO;
    cin >> n;
    memset(DP, -1, sizeof(int) * (n + 1));
    cout << function(n);
    return 0;
} // 반복적 동적 계획법으로 쓰면 더 간단히 풀릴 것 같긴 하다.