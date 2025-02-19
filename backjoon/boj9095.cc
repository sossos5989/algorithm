#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, list[11] = {0, 1, 2, 4};

int main() {
    fastIO;
    int C;
    cin >> C;
    for (int i = 4; i <= 10; i++) {
        list[i] = list[i - 1] + list[i - 2] + list[i - 3];
    }
    while (C--) {
        cin >> n;
        cout << list[n] << "\n";
    }
    return 0;
}