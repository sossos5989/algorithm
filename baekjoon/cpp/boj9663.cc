#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
int used[16];
int count = 0;
void backtrack(int x) {
    if (x > n) {
        count++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;

        bool flag = false;
        for (int j = 1; j <= x - 1; j++) {
            if ((i + j <= n && used[i + j] == x - j) ||
                (i - j >= 1 && used[i - j] == x - j)) {
                flag = true;
                break;
            }
        }
        if (flag) continue;

        used[i] = x;
        backtrack(x + 1);
        used[i] = 0;
    }
}

int main() {
    fastIO;
    cin >> n;
    backtrack(1);
    cout << count;
    return 0;
}