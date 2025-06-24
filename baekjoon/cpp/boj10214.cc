#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int t, y, k;
    cin >> t;
    while (t--) {
        int count = 0;
        for (int i = 0; i < 9; i++) {
            cin >> y >> k;
            count += y - k;
        }
        cout << (count > 0 ? "Yonsei" : (count == 0 ? "Draw" : "Korea"))
             << '\n';
    }
    return 0;
}