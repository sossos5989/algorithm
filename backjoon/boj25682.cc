#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, k, psum1[2001][2001], psum2[2001][2001], ans = 1e9;
char cache[2001];

int main() {
    fastIO;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> cache;
        for (int j = 0; j < m; j++) {
            int cost1 = ((i + j) % 2) ^ (cache[j] == 'B');
            int cost2 = 1 - cost1;
            psum1[i + 1][j + 1] =
                psum1[i][j + 1] + psum1[i + 1][j] - psum1[i][j] + cost1;
            psum2[i + 1][j + 1] =
                psum2[i][j + 1] + psum2[i + 1][j] - psum2[i][j] + cost2;
        }
    }
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            int sum1 = psum1[i][j] - psum1[i - k][j] - psum1[i][j - k] +
                       psum1[i - k][j - k];
            int sum2 = psum2[i][j] - psum2[i - k][j] - psum2[i][j - k] +
                       psum2[i - k][j - k];
            ans = min(ans, min(sum1, sum2));
        }
    }
    cout << ans;
    return 0;
}

// 개선 가능한 부분, 패턴이 정확히 반전이기에 psum1을 하나만 써도 됨.
// 어떤 패턴의 틀린 칸 개수를 x개라 하면
// psum1[i][j] = x, psum2[i][j] = i * j - x가 성립함을 알 수 있음.
// 따라서 공간을 아낄 수 있다.