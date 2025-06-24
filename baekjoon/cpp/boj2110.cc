#include <algorithm>
#include <iostream>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, c, list[200001];

bool decision(int len) {
    int cnt = c - 1;
    int last = list[0];
    for (int i = 1; i < n; i++) {
        if (list[i] - last >= len) {
            cnt--;
            last = list[i];
            if (cnt == 0) return true;
        }
    }
    return false;
}

int main() {
    fastIO;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> list[i];

    sort(list, list + n);

    int lo = 0, hi = 1e9 + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (decision(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo;
    return 0;
}