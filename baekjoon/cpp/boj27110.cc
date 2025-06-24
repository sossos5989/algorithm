#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << min(n, a) + min(n, b) + min(n, c);
    return 0;
}