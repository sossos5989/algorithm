#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << min(min(x, w - x), min(y, h - y));
    return 0;
}