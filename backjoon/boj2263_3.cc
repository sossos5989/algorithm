#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, in[100000], rev_post[100000], pos[100001];

void pre(int l, int r, int k) {
    if (l >= r) return;
    int rootVal = rev_post[k];
    int pivot = pos[rootVal];
    printf("%d ", rootVal);
    pre(l, pivot, k + (r - pivot));
    pre(pivot + 1, r, k + 1);
}

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        cin >> rev_post[i];
    }
    for (int i = 0; i < n; i++) {
        pos[in[i]] = i; // 중위 순회의 index를 미리 저장한다.
    }
    pre(0, n, 0);
    return 0;
}
