#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, m, k = 0, sum = 0;
    char s[1000001];
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        if (s[i] == 'I') {
            if (k % 2)
                k = 1;
            else
                k++;
        } else {
            if (k % 2)
                k++;
            else
                k = 0;
        }
        if (k == 2 * n + 1) {
            sum++;
            k -= 2;
        }
    }
    cout << sum;
    return 0;
} // kmp 알고리즘이랑 유사