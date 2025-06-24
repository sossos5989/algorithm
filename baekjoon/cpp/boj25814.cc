#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int func(int k) {
    int a = 0, b = 0;
    while (k) {
        a += k % 10;
        b++;
        k /= 10;
    }
    return a * b;
}

int decision(int x, int y) {
    int calx = func(x), caly = func(y);
    if (calx > caly)
        return 1;
    else if (calx < caly)
        return 2;
    return 0;
}

int main() {
    fastIO;
    int x, y;
    cin >> x >> y;
    cout << decision(x, y);
    return 0;
}