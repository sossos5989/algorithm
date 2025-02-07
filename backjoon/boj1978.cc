#include <iostream>
#include <math.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int NUM = 1000; // 문제에서 자연수의 최대 크기
int n, cache, count = 0;
bool isNotPrime[NUM + 1];

int main() {
    fastIO;
    cin >> n;
    int sqrtN = sqrt(NUM);
    isNotPrime[0] = isNotPrime[1] = 1;
    for (int i = 2; i <= sqrtN; i++) {
        if (isNotPrime[i]) continue;
        for (int j = i * i; j <= NUM; j += i) {
            isNotPrime[j] = 1;
        }
    }
    while (n--) {
        cin >> cache;
        if (!isNotPrime[cache]) count++;
    }
    cout << count;
    return 0;
} // 아리스토테네스의 체를 이용한다.