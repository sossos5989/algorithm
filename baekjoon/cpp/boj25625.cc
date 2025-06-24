#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int x, y;
    cin >> x >> y;
    cout << (x + y) % (2 * x);
    return 0;
}