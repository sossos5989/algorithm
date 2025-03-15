#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int a = 1, b = 1, c = 1;

int main() {
    fastIO;
    while (true) {
        cin >> a >> b >> c;
        if (!(a && b && c)) break;
        if (c < a) swap(a, c);
        if (c < b) swap(b, c);
        cout << (a * a + b * b == c * c ? "right\n" : "wrong\n");
    }
    return 0;
}