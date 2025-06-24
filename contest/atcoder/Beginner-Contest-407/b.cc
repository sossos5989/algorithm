#include <iostream>
#include <math.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int x, y;
    cin >> x >> y;

    int a = 0, b = 0, c = 0;
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++) {
            if (i + j >= x && abs(i - j) >= y) {
                c++;
            } else if (i + j >= x) {
                a++;
            } else if (abs(i - j) >= y) {
                b++;
            }
        }

    cout.precision(30);
    cout << double(a + b + c) / 36.0;
    return 0;
}