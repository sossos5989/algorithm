#include <iostream>
#include <math.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
bool isNotPrime[1000000 + 1];

int main() {
    fastIO;
    cin >> n >> m;
    isNotPrime[0] = isNotPrime[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        if (isNotPrime[i]) continue;
        for (int j = i * i; j <= 1000000; j += i) {
            isNotPrime[j] = 1;
        }
    }
    for (int i = n; i <= m; i++) {
        if (isNotPrime[i]) continue;
        cout << i << "\n";
    }
    return 0;
} // 아리스토테네스의 체를 이용한다.