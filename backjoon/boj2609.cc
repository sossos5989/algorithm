#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;

int gcb(int x, int y) {
    if (y == 0) return x;
    return gcb(y, x % y);
}

int main() {
    fastIO;
    cin >> n >> m;
    cout << gcb(n, m) << "\n" << n * m / gcb(n, m);
    return 0;
}