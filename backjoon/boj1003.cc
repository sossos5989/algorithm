#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int t, n;
    pair<int, int> fib[41];
    fib[0] = {1, 0};
    fib[1] = {0, 1};
    for (int i = 2; i < 41; i++) {
        fib[i] = {fib[i - 1].first + fib[i - 2].first,
                  fib[i - 1].second + fib[i - 2].second};
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << fib[n].first << " " << fib[n].second << "\n";
    }
    return 0;
} // pair<int, int>를 사용하지 않을 수도 있다.