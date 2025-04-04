#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

char str[101];

int main() {
    fastIO;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        str[i] = '-';
    }
    str[n / 2] = '=';
    if (n % 2 == 0) str[n / 2 - 1] = '=';
    cout << str;
    return 0;
}