#include <cstring>
#include <iostream>
#include <math.h>
#include <numeric>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k;
string input[15];
pair<int, int> da[15]; // 전처리 데이터
int tenModK[51];
long long factorial[16];

long long DP[1 << 15][100];
long long function(int mask, int mod) {
    if (__builtin_popcount(mask) == n) {
        return mod == 0;
    }
    long long &ret = DP[mask][mod];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) continue;
        mask |= (1 << i);
        ret += function(mask, (mod * tenModK[da[i].second] + da[i].first) % k);
        mask &= ~(1 << i);
    }
    return ret;
}

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cin >> k;
    for (int i = 0; i < n; i++) {
        int mod = 0;
        for (int j = 0; j < input[i].size(); j++) {
            mod *= 10;
            mod += (int)(input[i][j] - '0') % k;
            mod %= k;
        }
        da[i] = make_pair(mod, input[i].size());
    }

    factorial[0] = 1;
    for (int i = 1; i < 16; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    tenModK[1] = 10 % k;
    for (int i = 2; i < 51; i++) {
        tenModK[i] = (tenModK[i - 1] * 10) % k;
    }

    DP[0][0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int mod = 0; mod < k; mod++) {
            if (DP[mask][mod] == 0) continue;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) continue;
                int new_mask = mask | (1 << i);
                int new_mod =
                    ((long long)mod * tenModK[da[i].second] + da[i].first) % k;
                DP[new_mask][new_mod] += DP[mask][mod];
            }
        }
    }

    long long p = DP[(1 << n) - 1][0], q = factorial[n], g = gcd(p, q);
    cout << p / g << "/" << q / g;
    return 0;
} // 개선 가능하지만, 요정도까지만