#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, pre[100000], in[100000], pos[100001];

void post(int l, int r, int k) {
    if (l >= r) return;
    int rootVal = pre[k];
    int pivot = pos[rootVal];
    post(l, pivot, k + 1);
    post(pivot + 1, r, k + 1 + pivot - l);
    cout << rootVal << " ";
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> pre[i];
        for (int i = 0; i < n; ++i)
            cin >> in[i];
        for (int i = 0; i < n; i++) {
            pos[in[i]] = i;
        }
        post(0, n, 0);
        cout << "\n";
    }
    return 0;
}