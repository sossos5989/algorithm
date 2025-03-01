#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string a, b;
vector<int> indexA[26], indexB[26];

int DP[7001][7001];
int f(int n, int m) {
    int &ret = DP[n][m];
    if (ret != -1) return ret;
    if (n >= a.size() || m >= b.size()) return 0;
    if (a[n] == b[m]) {
        ret = 1 + f(n + 1, m + 1);
    } else {
        vector<int> &candA = indexA[b[n] - 'A'], candB = indexB[a[n] - 'A'];
        auto nn = upper_bound(candA.begin(), candA.end(), n);
        auto mm = upper_bound(candB.begin(), candB.end(), m);
        if (nn != candA.end()) {
            ret = max(ret, f(*nn - 1, m + 1) + 1);
            ret = max(ret, f(n + 1, *mm - 1) + 1);
        } else {
            ret = max(ret, 0);
        }
        if (mm != candB.end()) {
            ret = max(ret, f(n + 1, *mm - 1) + 1);
        } else {
            ret = max(ret, 0);
        }
        ret = max(ret, f(n + 1, m + 1));
    }
    return ret;
}

int main() {
    fastIO;
    memset(DP, -1, sizeof(DP));
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        indexA[a[i] - 'A'].push_back(i);
    }
    for (int i = 0; i < b.size(); i++) {
        indexB[b[i] - 'A'].push_back(i);
    }
    cout << f(0, 0);
    return 0;
}