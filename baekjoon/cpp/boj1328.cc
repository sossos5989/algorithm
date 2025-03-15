#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int MOD = 1000000007;
int N, L, R;

// 조합
int DP1[100][101];
void compute_combinations() {
    for (int i = 0; i <= L + R - 2; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                DP1[i][j] = 1; // Base Case
            else
                DP1[i][j] = (DP1[i - 1][j - 1] + DP1[i - 1][j]) % MOD;
        }
    }
}

// 스털링 수 공식을 변형한다.
int DP2[100][101];
void compute_S() {
    DP2[0][0] = 1;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j <= L + R - 2; j++) {
            if (i == j)
                DP2[i][j] = 1;
            else if (j == 0) {
                DP2[i][j] = 0;
            } else {
                DP2[i][j] = (DP2[i - 1][j - 1] +
                             ((long long)(i - 1) * DP2[i - 1][j]) % MOD) %
                            MOD;
            }
        }
    }
}

int main() {
    cin >> N >> L >> R;
    int ret = 0;
    if (L == 1 && R == 1 && N == 1) ret = 1;
    if (L + R >= 3 && L + R <= N + 1) {
        compute_combinations();
        compute_S();
        ret = ((long long)DP1[L + R - 2][L - 1] * DP2[N - 1][L + R - 2]) % MOD;
    }
    cout << ret << endl;
}
