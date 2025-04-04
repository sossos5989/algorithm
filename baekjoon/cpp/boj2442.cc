#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            cout << ' ';
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}