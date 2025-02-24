#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 80752;

int A[26][MAX];
pair<int, long long> B[MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, Q, r = 0, id = 0;
        cin >> N >> Q;
        memset(A, 0, sizeof A);
        memset(B, 0, sizeof B);
        while (N--) {
            char s[12] = {};
            int x, p = 0;
            long long a = 0;
            cin >> s >> x;
            for (int j = 0; s[j]; j++)
                a |= s[j] - 64LL << 50 - j * 5;
            for (int j = 0; s[j]; j++) {
                int &k = A[s[j] - 'A'][p];
                B[p] = min(B[p], {-x, a});
                p = k = k ? k : ++id;
            }
            B[p] = min(B[p], {-x, a});
        }
        while (Q--) {
            char s[12] = {};
            int x = 0, p = 0;
            long long a = 0;
            cin >> s;
            int n = strlen(s);
            for (int j = 0; s[j]; j++)
                a |= s[j] - 64LL << 50 - j * 5;
            for (int j = 0; s[j]; j++) {
                ++x;
                if (a == B[p].second) break;
                if (!(p = A[s[j] - 'A'][p])) {
                    x = n;
                    break;
                }
            }
            r += min(max(x, 2), n) + 1;
        }
        cout << r - 1 << '\n';
    }
}

// 출처: https://algospot.com/judge/submission/detail/627021
// bitmasking을 통해 극한으로 깎은 코드