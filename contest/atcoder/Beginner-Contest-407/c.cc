#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        int now = s[i] - '0';
        now = (now + 10000000 - b) % 10;
        b += now;
        a++;
    }
    cout << a + b;
    return 0;
}