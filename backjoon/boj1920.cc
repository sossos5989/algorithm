#include <algorithm>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, m, cache, A[100000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A, A + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> cache;
        cout << binary_search(A, A + n, cache) << "\n";
    }
    return 0;
}