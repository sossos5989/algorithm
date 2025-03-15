#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, x;

int main() {
    fastIO;
    int cache;
    cin >> n >> x;
    while (n--) {
        cin >> cache;
        if (cache < x) cout << cache << " ";
    }
    return 0;
}