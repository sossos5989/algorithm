#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int a, b;

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> a >> b;
        cout << a + b << "\n";
    }
    return 0;
}