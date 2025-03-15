#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, q, list[100001];
long long fenwick[100001];

void update(int idx, long long val) {
    for (; idx <= n; idx += idx & -idx)
        fenwick[idx] += val;
}

long long query(int idx) {
    long long ret = 0;
    for (; idx; idx &= idx - 1)
        ret += fenwick[idx];
    return ret;
}

int main() {
    fastIO;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> list[i];
        update(i, list[i]);
    } // init
    int x, y, a;
    long long b;
    while (q--) {
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        cout << query(y) - query(x - 1) << "\n";
        update(a, (long long)b - list[a]);
        list[a] = b;
    }
    return 0;
} // use Fenwick Tree