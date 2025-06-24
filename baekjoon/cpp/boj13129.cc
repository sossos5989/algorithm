#include <iostream>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    for (int i = 1; i <= n; i++)
        cout << a * n + b * i << ' ';
    return 0;
}