#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        if (i == n)
            cout << "53";
        else
            cout << i << ' ';
    }
    return 0;
}