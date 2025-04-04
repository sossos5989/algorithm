#include <algorithm>
#include <iostream>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int MAX = 40560;
vector<long long> prime, sub, add;
int visited[MAX], test[MAX];

int func(int mid) {
    int ans = mid;
    for (auto &i : sub) {
        long long cand = mid / i;
        if (cand == 0) break;
        ans -= cand;
    }

    for (auto &i : add) {
        long long cand = mid / i;
        if (cand == 0) break;
        ans += cand;
    }
    return ans;
}

int main() {
    fastIO;
    for (int i = 2; i < MAX; i++) {
        if (!visited[i]) {
            prime.push_back(i);
            for (int j = i; j < MAX; j += i) {
                visited[j] = i;
            }
        }
    } // linear-seive

    for (int i = 2; i < MAX; i++) {
        if (!test[i]) {
            int count = 0, now = i;
            vector<long long> cache;
            cache.push_back(i);
            while (now > 1) {
                count++;
                int cand = visited[now];
                now /= cand;

                int s = cache.size();
                for (int kk = 0; kk < s; kk++) {
                    long long hh = cache[kk] * cand;
                    while (1) {
                        if (hh >= MAX) break;
                        test[hh] = 1;
                        cache.push_back(hh);
                        hh *= cand;
                    }
                }
            }

            if (count % 2 == 1) {
                sub.push_back(i * i);
            } else {
                add.push_back(i * i);
            }
        }
    }

    long long k;
    cin >> k;

    int lo = 0, hi = 2 * 1e9;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        int ans = func(mid);

        if (ans <= k) {
            lo = mid;
            if (ans == k) break;
        } else {
            hi = mid;
        }
    }

    while (1) {
        if (func(lo - 1) < k) break;
        lo--;
    } // fine-tuning

    cout << lo;
    return 0;
}