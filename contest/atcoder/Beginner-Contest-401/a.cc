#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (c * 60 + d < a * 60 + b ? "Yes" : "No");
    return 0;
}