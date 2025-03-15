#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int t, n;
    long long list[101] = {0, 1, 1, 1, 2, 2};
    for (int i = 6; i <= 100; i++) {
        list[i] = list[i - 1] + list[i - 5];
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << list[n] << "\n";
    }
    return 0;
}