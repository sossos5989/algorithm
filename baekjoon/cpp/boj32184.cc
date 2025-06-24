#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << (a + 1) % 2 + b % 2 + (b - a + 1 - (a + 1) % 2 - b % 2) / 2;
    return 0;
}