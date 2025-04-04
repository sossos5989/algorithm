#include <cstring>
#include <iostream>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int inputTop[100001], inputDown[100001], dpTop[100001], dpDown[100001];

int main() {
    fastIO;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> inputTop[i];
        for (int i = 1; i <= n; i++)
            cin >> inputDown[i];

        memset(dpTop, 0, sizeof(int) * (n + 1));
        memset(dpDown, 0, sizeof(int) * (n + 1));

        dpTop[1] = inputTop[1], dpDown[1] = inputDown[1];
        for (int i = 2; i <= n; i++) {
            dpTop[i] = max(dpDown[i - 1], dpDown[i - 2]) + inputTop[i];
            dpDown[i] = max(dpTop[i - 1], dpTop[i - 2]) + inputDown[i];
        }

        cout << max(dpDown[n], dpTop[n]) << '\n';
    }
    return 0;
}