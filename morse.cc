#include <iostream>
#include <string>
#define fastIO cin.tie(0)->sync_with_stdio(0)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int n, m, k;

const int M = 1000000100;
int combTable[201][201];

void fillCombinations() {
    for (int i = 0; i < 201; i++) {
        combTable[i][0] = combTable[i][i] = 1;
        for (int j = 1; j <= i; j++) {
            combTable[i][j] = MIN(M, combTable[i-1][j-1] + combTable[i-1][j]);
        }
    }
}

string function(int n, int m, int k) {
    if (n == 0) return string(m, 'o');
    if (m == 0) return string(n, '-');
    
    int standard = combTable[n + m - 1][n - 1];
    if (k > standard) {
        return "o" + function(n, m - 1, k - standard);
    }
    return "-" + function(n - 1, m, k);
}

int main() {
    fastIO;
    fillCombinations();
    int repeat;
    cin >> repeat;
    while (repeat-- > 0) {
        cin >> n >> m >> k;
        cout << function(n, m, k) << "\n";
    }
    return 0;
}
