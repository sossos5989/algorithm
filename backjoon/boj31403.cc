#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int a, b, c;

int main() {
    fastIO;
    cin >> a >> b >> c;
    int repeat = b, th = 1;
    while (repeat) {
        th *= 10;
        repeat /= 10;
    }
    cout << (a + b - c) << "\n" << (a * th + b - c);
    return 0;
}