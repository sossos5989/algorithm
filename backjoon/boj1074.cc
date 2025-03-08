#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, r, c;
    cin >> n >> r >> c;
    int count = 0;
    int sz = 1 << (n - 1);
    while (sz) {
        if (r >= sz) {
            r -= sz;
            count += sz * sz * 2;
        }
        if (c >= sz) {
            c -= sz;
            count += sz * sz;
        }
        sz /= 2;
    }
    cout << count;
    return 0;
}