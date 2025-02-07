#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k;

int combination(int a, int b) {
    if (a == b || b == 0) return 1;
    return combination(a - 1, b - 1) + combination(a - 1, b);
} // 메모이제이션을 적용하진 않았다.

int main() {
    fastIO;
    cin >> n >> k;
    cout << combination(n, k);
    return 0;
}