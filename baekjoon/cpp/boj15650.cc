#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
int num[9];
void backtrack(int start, int x) {
    if (x == 0) {
        for (int i = 1; i <= n; i++) {
            if (num[i]) cout << i << " ";
        }
        cout << "\n";
    } else {
        for (int i = start; i <= n; i++) {
            if (num[i] == 0) {
                num[i] = 1;
                backtrack(i + 1, x - 1);
                num[i] = 0;
            }
        }
    }
}

int main() {
    fastIO;
    cin >> n >> m;
    backtrack(1, m);
    return 0;
}