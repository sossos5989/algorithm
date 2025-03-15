#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
vector<string> input;

char standard;
bool visited[101][101];
void dfs(int x, int y) {
    visited[x][y] = 1;
    if (x + 1 < n && !visited[x + 1][y] && standard == input[x + 1][y])
        dfs(x + 1, y);
    if (y + 1 < n && !visited[x][y + 1] && standard == input[x][y + 1])
        dfs(x, y + 1);
    if (x - 1 >= 0 && !visited[x - 1][y] && standard == input[x - 1][y])
        dfs(x - 1, y);
    if (y - 1 >= 0 && !visited[x][y - 1] && standard == input[x][y - 1])
        dfs(x, y - 1);
} // 끄아악 하드코딩

int main() {
    fastIO;
    cin >> n;
    input.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int normal = 0, abnormal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                standard = input[i][j];
                dfs(i, j);
                normal++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (input[i][j] == 'G') input[i][j] = 'R';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                standard = input[i][j];
                dfs(i, j);
                abnormal++;
            }
        }
    }
    cout << normal << " " << abnormal;
    return 0;
}