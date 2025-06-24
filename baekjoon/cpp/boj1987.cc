#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int r, c;
vector<string> input;
bool alphabet[26], visited[20][20];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int backtrack(int x, int y) {
    int ret = 0;
    alphabet[input[x][y] - 'A'] = 1;
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || yy < 0 || xx >= r || yy >= c) continue;
        if (!visited[xx][yy] && !alphabet[input[xx][yy] - 'A'])
            ret = max(ret, backtrack(xx, yy) + 1);
    }

    alphabet[input[x][y] - 'A'] = 0;
    visited[x][y] = 0;

    return ret;
}

int main() {
    fastIO;
    cin >> r >> c;
    input.resize(r);
    for (int i = 0; i < r; i++) {
        cin >> input[i];
    }
    cout << backtrack(0, 0) + 1;

    return 0;
}