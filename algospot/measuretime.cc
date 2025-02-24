#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, input, fenwick[1000001];

void update(int i) {
    i++; // 이거 중요
    for (; i <= 1000000; i += i & -i)
        fenwick[i]++;
}

int query(int i) {
    i++; // 이거 중요
    int ret = 0;
    for (; i; i -= i & -i)
        ret += fenwick[i];
    return ret;
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n;
        int sum = 0;
        memset(fenwick, 0, sizeof(fenwick));
        for (int i = 0; i < n; i++) {
            cin >> input;
            sum += i - query(input);
            update(input);
        }
        cout << sum << "\n";
    }
    return 0;
}