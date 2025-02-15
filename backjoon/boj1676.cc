#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;

int main() {
    fastIO;
    cin >> n;
    cout << n / 5 + n / 25 + n / 125;
    return 0;
}
