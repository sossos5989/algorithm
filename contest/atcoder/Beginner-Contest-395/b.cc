#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    char grid[51][51];
    cin >> n;

    for (int k = 0; k <= (n + 1) / 2; k++) {
        for (int i = 0 + k; i + k < n; i++) {
            for (int j = 0 + k; j + k < n; j++) {
                if (k % 2 == 0)
                    grid[i][j] = '#';
                else
                    grid[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}