#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, flag = 0, i = 1;
    cin >> n;
    for (i = 1; n - i >= 0; i++) {
        flag = !flag;
        n -= i;
    }
    if (flag)
        cout << 0;
    else
        cout << i - n;
    return 0;
}