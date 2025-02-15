#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, q, input[100000], a, b;
pair<int, int> seg[400000]; // {max, min}

pair<int, int> init(int node, int start, int end) {
    if (start == end) return seg[node] = make_pair(input[start], input[start]);
    int mid = (start + end) / 2;
    pair<int, int> left = init(node * 2, start, mid);
    pair<int, int> right = init(node * 2 + 1, mid + 1, end);
    seg[node].first = max(left.first, right.first);
    seg[node].second = min(left.second, right.second);
    return seg[node];
}

pair<int, int> query(int left, int right, int node, int nodeLeft,
                     int nodeRight) {
    if (nodeRight < left || right < nodeLeft) return make_pair(-20000, 20000);
    if (left <= nodeLeft && nodeRight <= right) return seg[node];
    int mid = (nodeLeft + nodeRight) / 2;
    pair<int, int> cand1 = query(left, right, node * 2, nodeLeft, mid);
    pair<int, int> cand2 = query(left, right, node * 2 + 1, mid + 1, nodeRight);
    return make_pair(max(cand1.first, cand2.first),
                     min(cand1.second, cand2.second));
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> input[i];
        }
        init(1, 0, n - 1);
        while (q--) {
            cin >> a >> b;
            pair<int, int> cache = query(a, b, 1, 0, n - 1);
            cout << cache.first - cache.second << "\n";
        }
    }
    return 0;
}