#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int x, y;
int main() {
    fastIO;
    cin >> x >> y;
    cout << (x > 0 ? y > 0 ? 1 : 4 : y > 0 ? 2 : 3);
    return 0;
}