#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, ret = 1;

int main() {
    fastIO;
    cin >> n;
    for (int i = 1; n > 1; i++, ret++) {
        n -= 6 * i;
    }
    cout << ret;
    return 0;
}
