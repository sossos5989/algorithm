#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int MOD = 20091101;

int n, k;
int D[100001], psum[100001];

int main() {
    fastIO;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> D[i];
        }

        vector<long long> count(k, 0);
        count[0] = 1;
        for (int i = 1; i <= n; i++) {
            psum[i] = (psum[i - 1] + D[i]) % k;
            count[psum[i]]++;
        }

        int ret = 0;
        for (int i = 0; i < k; i++) {
            if (count[i] >= 2)
                ret = (ret + ((count[i] * (count[i] - 1)) / 2)) % MOD;
        }

        vector<int> DP(n + 1, 0);
        vector<int> prev(k, -1);
        prev[0] = 0;
        for (int i = 1; i <= n; i++) {
            int &cache = prev[psum[i]];
            DP[i] = DP[i - 1];
            if (cache != -1 && DP[i] < DP[cache] + 1) {
                DP[i] = DP[cache] + 1;
            }
            cache = i;
        }

        cout << ret << " " << DP[n] << endl;
    }
    return 0;
}