#include <cstring>
#include <iostream>
#include <math.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int MAX = 10000000;
int n, lo, hi; // n개의 약수를 가지는 lo <= k <= hi 범위 내의 수의 개수를 구하기

int factors[MAX + 1];

void init() {
    for (int i = 1; i <= MAX; i++) {
        for (int j = i; j <= MAX; j += i) {
            factors[j] += 1;
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