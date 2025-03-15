#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, cache, board[128][128];

void sum(pair<int, int> &p1, const pair<int, int> &p2) {
    p1.first += p2.first;
    p1.second += p2.second;
}

pair<int, int> dfs(int x, int y, int size) {
    // base case
    if (size == 1 && board[x][y] == 1) return make_pair(1, 0);
    if (size == 1 && board[x][y] == -1) return make_pair(0, 1);
    int next_size = size / 2;
    pair<int, int> count = make_pair(0, 0);
    sum(count, dfs(x, y, next_size));
    sum(count, dfs(x + next_size, y, next_size));
    sum(count, dfs(x, y + next_size, next_size));
    sum(count, dfs(x + next_size, y + next_size, next_size));
    if (count.first == 4 && count.second == 0) return make_pair(1, 0);
    if (count.first == 0 && count.second == 4) return make_pair(0, 1);
    return count; // 섞여있음
}

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cache;
            board[i][j] = cache ? 1 : -1;
        }
    }
    auto it = dfs(0, 0, n);
    cout << it.second << "\n" << it.first;
    return 0;
}