#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, t, c, p;
    cin >> n >> t >> c >> p;
    cout << ((n - 1) / t) * c * p;
    return 0;
}