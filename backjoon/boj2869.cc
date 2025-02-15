#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

long a, b, v;

int main() {
    fastIO;
    cin >> a >> b >> v;
    cout << (v + a - 2 * b - 1) / (a - b);
    return 0;
}