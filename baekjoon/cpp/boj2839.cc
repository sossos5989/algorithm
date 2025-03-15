#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, left;
    cin >> n;
    if (n == 4 || n == 7)
        n = -1;
    else {
        left = n % 5;
        n /= 5;
        while (1) {
            if (left % 3) {
                n--;
                left += 5;
            } else {
                n += left / 3;
                break;
            }
        }
    }
    cout << n;
    return 0;
}