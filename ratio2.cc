#include <cmath>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long n, m;

int main() {
    fastIO;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int z = (m * 100) / n + 1;
        int dy = (z * n - 100 * m), dx = (100 - z);
        long long answer = (z >= 100) ? -1 : ceil((double)dy / dx);
        cout << answer << endl;
    }
    return 0;
}