#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int a, b, n, w, flag = 0, sheep, goat;
    cin >> a >> b >> n >> w;
    for (int i = 1; i < n; i++) {
        int cand = a * i + b * (n - i);
        if (cand == w) {
            flag++;
            sheep = i, goat = n - i;
        }
    }
    if (flag == 1)
        cout << sheep << ' ' << goat;
    else
        cout << -1;
    return 0;
}