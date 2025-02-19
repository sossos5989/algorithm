#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k, tree[1 << 18];
void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = 1;
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
} // tree[start, end]범위는 원소가 1이다.

int query(int node, int start, int end, int idx) {
    tree[node]--; // 펜윅 트리처럼 재귀적으로 지워짐
    if (start == end) return end;
    int mid = (start + end) / 2;
    if (idx > tree[node * 2])
        return query(node * 2 + 1, mid + 1, end, idx - tree[node * 2]);
    else
        return query(node * 2, start, mid, idx);
}

int main() {
    fastio;
    cin >> n >> k;
    init(1, 1, n);
    cout << "<";
    int idx = 0;
    for (int i = n; i > 1; --i) {
        idx += k - 1;
        idx %= i;
        cout << query(1, 1, n, idx + 1) << ", ";
    }
    cout << query(1, 1, n, 1) << ">";
}

// 인상적인 코드여서 가져와봄, 조금 수정함
// 출처: minjun0723, https://www.acmicpc.net/source/85978589
