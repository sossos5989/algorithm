#include <algorithm>
#include <iostream>
using namespace std;

int n, board[50], cache[50][50];

int play(int left, int right) {
    if (left > right) return 0;
    int &ret = cache[left][right];
    if (ret != -500001) return ret;
    ret = max(board[left] - play(left + 1, right),
              board[right] - play(left, right - 1));
    if (right - left + 1 >= 2)
        ret = max(ret, max(-play(left + 2, right), -play(left, right - 2)));
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 50; i++)
            for (int j = 0; j < 50; j++)
                cache[i][j] = -500001;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> board[i];
        cout << play(0, n - 1) << endl;
    }
    return 0;
}