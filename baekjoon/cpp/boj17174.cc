#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = n;
    while (n) {
        ans += n / m;
        n /= m;
    }
    cout << ans;
    return 0;
}