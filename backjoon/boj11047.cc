#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, k, count = 0, A[10];
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    while (n-- && k) {
        int value = A[n];
        count += k / value;
        k %= value;
    }
    cout << count;
    return 0;
}