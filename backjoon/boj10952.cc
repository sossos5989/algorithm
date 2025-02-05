#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int a = 1, b = 1;

int main() {
    fastIO;
    while (cin >> a >> b && (a && b)) {
        cout << a + b << "\n";
    }
    return 0;
}