#include <iostream>
#include <math.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, lo, hi; // n개의 약수를 가지는 lo <= k <= hi 범위 내의 수의 개수를 구하기

// 약수 개수 파악(소인수 판별 이용)
int count(int k) {
    int ret = 1;
    int sqrtK = sqrt(k);
    for (int i = 2; i <= sqrtK; i++) {
        int cache = 1;
        while (k % i == 0) {
            k /= i;
            cache++;
        }
        ret *= cache;
    }
    if (k > 1) ret *= 2; // 이 코드가 중요
    return ret;
}

int answer() {
    int ret = 0;
    for (int i = lo; i <= hi; i++) {
        if (count(i) == n) ret++;
    }
    return ret;
}

int main() {
    fastIO;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> lo >> hi;
        cout << answer() << endl;
    }
    return 0;
}