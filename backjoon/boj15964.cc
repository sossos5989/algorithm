#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

long a, b;

int main() {
    fastIO;
    cin >> a >> b;
    cout << (a + b) * (a - b) << "\n";
    return 0;
}