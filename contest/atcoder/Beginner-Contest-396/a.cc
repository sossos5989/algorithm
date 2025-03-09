#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool isStreak = false;
    for (int i = 0; i < n - 2; i++) {
        if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
            isStreak = true;
            break;
        }
    }

    cout << (isStreak ? "Yes" : "No");
    return 0;
}