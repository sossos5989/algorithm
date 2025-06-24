#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    double a, b;
    cin >> a >> b;
    cout << int((a + (b / 2)) / b);
    return 0;
}