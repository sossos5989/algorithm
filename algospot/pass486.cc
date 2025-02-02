#include <iostream>
#include <math.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int MAX = 10000000;
int n, lo, hi; // n개의 약수를 가지는 lo <= k <= hi 범위 내의 수의 개수를 구하기

int minFactor[MAX + 1], minFactorPower[MAX + 1], factors[MAX + 1];

void init() {
    // 에라토스테네스의 체를 이용해 정수 k의 최소 소인수를 구한다.
    minFactor[0] = minFactor[1] = -1; // 존재하지 않음
    for (int i = 2; i <= MAX; i++) {
        minFactor[i] = i; // 소수임을 의미한다.
    }
    int sqrtMAX = sqrt(MAX);
    for (int i = 2; i <= sqrtMAX; i++) {
        if (minFactor[i] == i) {
            for (int j = i * i; j <= MAX; j += i) {
                if (minFactor[j] == j) minFactor[j] = i;
            }
        }
    }

    // 앞서 구한 minFactor[]를 이용해 factors를 구한다.
    factors[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        if (minFactor[i] == i) {
            minFactorPower[i] = 1;
            factors[i] = 2; // 소수임을 의미합니다.
        } else {
            int m = i / minFactor[i];
            if (minFactor[i] != minFactor[m]) {
                minFactorPower[i] = 1; // 이제 이 소인수를 더 이상 쓸 수 없음
            } else {
                minFactorPower[i] = minFactorPower[m] + 1;
            }
            int a = minFactorPower[i];
            factors[i] = (factors[m] / a) * (a + 1);
        }
    }
}

int answer() {
    int count = 0;
    for (int i = lo; i <= hi; i++) {
        if (factors[i] == n) count++;
    }
    return count;
}

int main() {
    fastIO;
    int T;
    cin >> T;
    init();
    while (T--) {
        cin >> n >> lo >> hi;
        cout << answer() << endl;
    }
    return 0;
}