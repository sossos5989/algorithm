#include <algorithm>
#include <iostream>

#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, input;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        v.push_back({-input, i});
    }

    sort(v.begin(), v.end());

    int rank = 1, cnt = 0, pv = v[0].first, ans[101];
    for (auto &i : v) {
        if (pv == i.first) {
            ans[i.second] = rank;
            cnt++;
        } else {
            pv = i.first;
            rank += cnt;
            cnt = 1;
            ans[i.second] = rank;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}