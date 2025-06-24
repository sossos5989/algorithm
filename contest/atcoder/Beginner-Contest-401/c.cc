#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, a[300001];

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> v;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1])
            v.push_back(1);
        else
            v.push_back(-1);
    }

    vector<pair<int, long long>> runs;
    for (int d : v) {
        if (runs.empty() || runs.back().first != d) {
            runs.push_back({d, 1});
        } else {
            runs.back().second++;
        }
    }

    long long ans = 0;
    for (int i = 0; i + 2 < runs.size(); i++) {
        if (runs[i].first == 1 && runs[i + 1].first == -1 &&
            runs[i + 2].first == 1) {
            ans += runs[i].second * runs[i + 2].second;
        }
    }

    cout << ans;

    return 0;
}