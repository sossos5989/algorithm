#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    int m, k, mask = 0;
    cin >> m;
    string cache;
    while (m--) {
        cin >> cache;
        if (cache == "add") {
            cin >> k;
            mask |= (1 << k);
        } else if (cache == "remove") {
            cin >> k;
            mask &= ~(1 << k);
        } else if (cache == "check") {
            cin >> k;
            cout << (bool)(mask & (1 << k)) << "\n";
        } else if (cache == "toggle") {
            cin >> k;
            mask ^= (1 << k);
        } else if (cache == "all") {
            mask = 0b111111111111111111110;
        } else if (cache == "empty") {
            mask = 0;
        }
    }
    return 0;
}