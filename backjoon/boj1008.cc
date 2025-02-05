#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int a, b;

int main() {
    fastIO;
    cout.precision(10);
    cin >> a >> b;
    cout << (double)a / b;
    return 0;
}