#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << __builtin_popcount(n ^ (~n + 1));
    return 0;
}