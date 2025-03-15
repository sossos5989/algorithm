#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k, list[15][15];

void init() {
    for (int i = 1; i < 15; i++) {
        list[0][i] = i;
    }
    for (int i = 1; i < 15; i++) {
        int sum = 0;
        for (int j = 1; j < 15; j++) {
            sum += list[i - 1][j];
            list[i][j] = sum;
        }
    }
}

int main() {
    fastIO;
    init();
    int C;
    cin >> C;
    while (C--) {
        cin >> n >> k;
        cout << list[n][k] << "\n";
    }
    return 0;
}