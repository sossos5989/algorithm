#include <iostream>
#include <vector>
using namespace std;

#define fastIO cin.tie(0)->sync_with_stdio(0)

vector<vector<char>> triangle = {{' ', ' ', '*', ' ', ' '},
                                 {' ', '*', ' ', '*', ' '},
                                 {'*', '*', '*', '*', '*'}};

vector<vector<char>> func(int k) {
    if (k == 0) return triangle;

    vector<vector<char>> prev = func(k - 1);
    int h = prev.size(), w = prev[0].size();

    vector<vector<char>> ret(h * 2, vector<char>(w * 2 + 1, ' '));

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            ret[i][w / 2 + j + 1] = ret[h + i][j] = ret[h + i][w + j + 1] =
                prev[i][j];

    return ret;
}

int main() {
    fastIO;
    int n, cnt = -2;
    cin >> n;

    while (n) {
        cnt++;
        n >>= 1;
    }

    vector<vector<char>> ret = func(cnt);
    for (auto &i : ret) {
        for (auto &j : i)
            cout << j;
        cout << '\n';
    }

    return 0;
}