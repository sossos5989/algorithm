#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, a[300001];
int count[300001];
int c2[300001];

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    int distinct = 0;
    for (int i = 0; i <= n; i++) {
        if (count[i]) distinct++;
    }

    int left = 1, right = distinct;
    count[a[0]]--;
    c2[a[0]]++;
    if (count[a[0]] == 0) right--;

    int gap = left + right;
    for (int i = 1; i < n - 1; i++) {
        if (count[a[i]] == 1) right--;
        if (c2[a[i]] == 0) left++;
        count[a[i]]--;
        c2[a[i]]++;
        // cout << left + right << "\n";
        gap = max(gap, left + right);
    }
    cout << gap;
    return 0;
}