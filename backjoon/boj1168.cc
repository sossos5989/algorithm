#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k, fen[100001];

void update(int idx, int val) {
    for (; idx <= n; idx += (idx & -idx))
        fen[idx] += val;
} // 펜윅 트리의 값을 업데이트, O(log n)

int query(int idx) {
    int ret = 0;
    for (; idx; idx &= idx - 1)
        ret += fen[idx];
    return ret;
} // 펜윅 트리를 이용해 idx의 값을 찾음, O(log n)

int optimize(int x) {
    int lo = 0, hi = n + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (query(mid) < x)
            lo = mid;
        else
            hi = mid;
    }
    return hi;
} // x번째인 원소의 값을 이분탐색을 이용해 파악하는 함수

int main() {
    fastIO;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        update(i, 1);
    cout << "<";
    int v = k;
    for (int i = n - 1; i >= 1; i--) {
        int now = optimize(v);
        update(now, -1); // now에 해당하는 값(size)를 지운다.
        v += k - 1;      // 지웠으니, k-1개를 지운다.
        v = (v - 1) % i + 1; // 1-based index이므로, 이렇게 modulo연산을 한다.
        cout << now << ", ";
    }
    cout << optimize(1) << ">"; // 마지막은 무조건 index가 1이다.
    return 0;
}