#include <cstring>
#include <iostream>
#include <math.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int DP[50001][4];
int function(int k, int count) {
    int &ret = DP[k][count];
    int sqrtK = (int)sqrt(k);
    if (ret != -1) return ret;
    if (count == 4) return 4;
    if (k == 0) return count;
    ret = 4;
    for (int i = 1; i <= sqrtK; i++) {
        ret = min(ret, function(k - i * i, count + 1));
    }
    return ret;
}

int main() {
    fastIO;
    int n;
    cin >> n;
    memset(DP, -1, sizeof(DP));
    cout << function(n, 0);
    return 0;
} // 3중 반복문으로 풀 수도 있다.