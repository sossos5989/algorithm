#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;

int main() {
    fastIO;
    cin >> n;
    for (int i = 1; i <= 9; i++) {
        cout << n << " * " << i << " = " << n * i << endl;
    }
    return 0;
}