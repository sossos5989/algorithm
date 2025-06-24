#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, row[50], col[50];
char c;

int main() {
    fastIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == 'X') {
                row[i] = 1;
                col[j] = 1;
            }
        }

    int cntRow = 0, cntCol = 0;
    for (int i = 0; i < n; i++)
        if (!row[i]) cntRow++;

    for (int i = 0; i < m; i++)
        if (!col[i]) cntCol++;

    cout << max(cntRow, cntCol);
    return 0;
}