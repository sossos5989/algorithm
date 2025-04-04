#include <iostream>
#include <math.h>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    double list[101];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    bool b = false;

    for (int i = 0; i < n; i++) {
        double lo = 0.0, hi = 255.0;
        bool contradict = 0;
        for (int it = 100; it >= 0; it--) {
            int state = 0;
            double mid = (lo + hi) / 2.0;
            // cout << mid << "\n";
            for (int k = 0; k < n; k++) {
                if (i == k) continue;
                double cand = list[i] + double(k - i) * mid;
                if (k < i) { // 귀찮아서 하드코딩
                    if (cand < list[k] && state != -1)
                        state = 1;
                    else if (cand >= list[k] + 1.0 && state != 1)
                        state = -1;
                    else if (list[k] <= cand && cand < list[k] + 1.0) {

                    } else {
                        contradict = 1;
                        break;
                    }
                } else if (k > i) {
                    if (cand < list[k] && state != 1)
                        state = -1;
                    else if (cand >= list[k] + 1.0 && state != -1)
                        state = 1;
                    else if (list[k] <= cand && cand < list[k] + 1.0) {

                    } else {
                        contradict = 1;
                        break;
                    }
                }
            }

            if (contradict) break; // 모순 발생

            if (state == -1)
                lo = mid;
            else if (state == 1)
                hi = mid;
            else {
                b = true;
                break;
            }
        }

        if (b) break;
    }

    cout << (b ? "pass" : "fail");

    return 0;
}