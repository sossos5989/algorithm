#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, list[301], DP[301];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }
    DP[0] = 0;
    DP[1] = list[1];
    DP[2] = list[1] + list[2];
    for (int i = 3; i <= n; i++) {
        DP[i] = max(DP[i - 3] + list[i - 1] + list[i], DP[i - 2] + list[i]);
    }
    cout << DP[n];
    return 0;
}