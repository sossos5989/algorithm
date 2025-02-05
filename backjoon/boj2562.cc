#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int cache, max = 0, index;
    for (int i = 1; i <= 9; i++) {
        cin >> cache;
        if (cache > max) {
            max = cache;
            index = i;
        }
    }
    cout << max << "\n" << index;
    return 0;
}