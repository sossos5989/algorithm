#include <iostream>
#include <cstring>
using namespace std;

int BOUND = 10000000;
int n;
int cache[101][101];

int function(int n, int prev) {
    if (n <= 0) return 1;

    int& ret = cache[n][prev];
    if (ret != -1) return ret;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = (sum + (prev + i - 1) * function(n - i, i)) % BOUND;
    }
    return ret = sum;
}

int main() {
    ios::sync_with_stdio(false); // 입출력 최적화
    cin.tie(nullptr);

    int repeat;
    cin >> repeat;
    memset(cache, -1, sizeof(cache)); // 한 번만 초기화
    while (repeat-- > 0) {
        cin >> n;

        int ret = 0;
        for (int i = 1; i <= n; i++) {
            ret = (ret + function(n - i, i)) % BOUND;
        }
        cout << ret << "\n";
    } 
    return 0;
}
