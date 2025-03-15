#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
double cache, sum, hi;

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cache;
        hi = max(hi, cache);
        sum += cache;
    }
    cout << (sum * 100.0) / (n * hi);
    return 0;
}