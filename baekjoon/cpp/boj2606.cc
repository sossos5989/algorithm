#include <iostream>
#include <numeric>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int element[101], r[101];

int find(int x) {
    if (x == element[x]) return x;
    return element[x] = find(element[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (r[x] > r[y]) {
        element[y] = x;
    } else {
        element[x] = y;
        if (r[x] == r[y]) r[y]++;
    }
}

int main() {
    fastIO;
    int n, m, u, v, count = 0;
    cin >> n >> m;
    iota(element, element + n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        merge(u, v);
    }
    for (int i = 2; i <= n; i++) {
        if (find(1) == find(i)) count++;
    }
    cout << count;
    return 0;
} // Union-find