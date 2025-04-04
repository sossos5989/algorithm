#include <cstring>
#include <iostream>
#include <numeric>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// 걍 귀찬아서 브루트포스
int main() {
    fastIO;
    int t;
    cin >> t;
    int m, n, x, y;
    bool visited[40001];
    while (t--) {
        memset(visited, 0, sizeof(visited));
        cin >> m >> n >> x >> y;
        x--, y--;
        int ans = x; // 0-based로 바꿈
        while (1) {
            if (ans % n == y) break;
            if (visited[ans % n] == 1) {
                ans = -2;
                break;
            }
            visited[ans % n] = 1;
            ans += m;
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}