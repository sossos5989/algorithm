#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, cache, P[1001] = {0}, ret = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cache;
        P[cache]++;
    }
    for (int i = 1; i <= 1000; i++) {
        int &k = P[i];
        ret += i * (n * k - ((k - 1) * k) / 2);
        n -= k;
    }
    cout << ret;
    return 0;
}