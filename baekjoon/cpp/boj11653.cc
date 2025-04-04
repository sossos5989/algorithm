#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << "\n";
            n /= i;
        }
    }
    if (n > 1) cout << n << '\n';
    return 0;
}