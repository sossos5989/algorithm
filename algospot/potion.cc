#include <cmath>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// n은 재료의 개수, r[]은 비율, p[]는 지금까지 넣은 양
int n, r[1000], p[1000];

// 1. 비율을 먼저 최대 공약수를 구해 나눔 (비율 최적화)
// 2. 그 다음, 현재 넣은 재료 p_i / r_i로 나누면
// 3. 이것이 전부 최대공약수 * 1 미만인지 확인,
// 왜? 최대공약수로 나눴으니깐
// 4. 최대공약수보다 크면, upper(p_i / r_i)인 정수를 기준으로(이게 만들 병수
// 느낌)
// 값을 구함

// C++17에서는 gcd함수를 지원하긴함
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int getGcdN() {
    int ret = r[0];
    for (int i = 1; i < n; i++) {
        ret = gcd(ret, r[i]);
    }
    return ret;
}

void readInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
}

void answer() {
    int gcdN = getGcdN();
    for (int i = 0; i < n; i++) {
        r[i] /= gcdN;
    }
    int multiple = 0;
    for (int i = 0; i < n; i++) {
        multiple = max(multiple, (int)ceil((double)p[i] / r[i]));
    }
    if (multiple < gcdN) multiple = gcdN;
    for (int i = 0; i < n; i++) {
        cout << multiple * r[i] - p[i] << " ";
    }
    cout << endl;
}

int main() {
    fastIO;
    int T;
    cin >> T;
    while (T--) {
        readInput();
        answer();
    }
    return 0;
}