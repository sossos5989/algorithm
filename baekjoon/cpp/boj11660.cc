#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int psum[1025][1025];

int main() {
    fastIO;
    int n, m, x1, y1, x2, y2, board[1025][1025];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] +
                         board[i][j];

    while (m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] +
                    psum[x1 - 1][y1 - 1]
             << '\n';
    }
    return 0;
}