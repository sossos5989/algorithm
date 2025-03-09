#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;
    vector<long long> black(n), white(m);
    for (int i = 0; i < n; i++) {
        cin >> black[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> white[i];
    }

    sort(black.begin(), black.end(), greater<long long>());
    sort(white.begin(), white.end(), greater<long long>());

    int plus =
        lower_bound(black.begin(), black.end(), 0, greater<long long>()) -
        black.begin() - 1;
    vector<long long> psumblack(n), psumwhite(m);
    psumblack[0] = black[0];
    psumwhite[0] = white[0];
    for (int i = 1; i < n; i++) {
        psumblack[i] = psumblack[i - 1] + black[i];
        // psumblack[i] += psumblack[i - 1] + black[i];
    }
    for (int i = 1; i < m; i++) {
        psumwhite[i] = psumwhite[i - 1] + white[i];
        // psumwhite[i] += psumwhite[i - 1] + white[i];
    }

    long long ans = 0;
    if (plus != -1) ans = max(ans, psumblack[plus]);

    for (int i = 0; i < min(n, m); i++) {
        long long cand = psumwhite[i];
        if (i <= plus)
            cand += psumblack[plus];
        else
            cand += psumblack[i];
        ans = max(ans, cand);
    }
    cout << ans;
    return 0;
}