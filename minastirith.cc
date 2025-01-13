#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat--) {
        int n;
        cin >> n;
        vector<pair<double, double>> arcs(n);
        bool singleOk = false;
        for (int i = 0; i < n; i++) {
            double y, x, r;
            cin >> y >> x >> r;
            if (r >= 16.0) singleOk = true;
            double mid = fmod(atan2(x, y) + 2.0 * M_PI, 2.0 * M_PI);
            double delta = 2.0 * asin(r / 16.0);
            arcs[i] = make_pair(mid - delta, mid + delta);
        }
        sort(arcs.begin(), arcs.end());

        if (singleOk) {
            cout << 1 << "\n";
            continue;
        }

        int ans = 111111111;
        bool anySuccess = false;
        for (int i = 0; i < n; i++) {
            if (arcs[i].first <= 0 || arcs[i].second >= 2.0 * M_PI) {
                bool localCover = true;
                double begin = fmod(arcs[i].second, 2.0 * M_PI);
                double end = fmod(arcs[i].first + 2.0 * M_PI, 2.0 * M_PI);
                int used = 1, idx = 0;
                while (begin < end) {
                    double mx = -1;
                    while (idx < n && arcs[idx].first <= begin) {
                        mx = max(mx, arcs[idx].second);
                        idx++;
                    }
                    if (mx <= begin) {
                        localCover = false;
                        break;
                    }
                    begin = mx;
                    used++;
                }
                if (localCover) {
                    anySuccess = true;
                    ans = min(ans, used);
                }
            }
        }

        if (!anySuccess) {
            cout << "IMPOSSIBLE\n";
        } else {
            if (ans == 111111111)
                cout << "IMPOSSIBLE\n";
            else
                cout << ans << "\n";
        }
    }
    return 0;
}
