#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    long long n;
    cin >> n;
    cout << (n * (n - 1) * (n - 2)) / 6 << '\n' << 3;
    return 0;
}