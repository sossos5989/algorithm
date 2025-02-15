#include <iostream>
using namespace std;
int a[31];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x = 0;
    double exc;
    int sum = 0;
    cin >> n;
    exc = (int)((double)n * 0.15 + 0.5);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[k]++;
    }
    for (int i = 1; i <= exc; i++) {
        if (a[x] > 0)
            a[x]--;
        else if (a[x] == 0) {
            x++;
            i--;
        }
    }
    x = 30;
    for (int i = 1; i <= exc; i++) {
        if (a[x] > 0)
            a[x]--;
        else if (a[x] == 0) {
            x--;
            i--;
        }
    }
    for (int i = 1; i < 31; i++) {
        sum += a[i] * i;
    }
    if (n == 0)
        cout << 0;
    else
        cout << (int)((double)sum / (n - 2 * exc) + 0.5);
}