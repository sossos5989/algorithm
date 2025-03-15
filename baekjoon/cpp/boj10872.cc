#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, ret = 1;
int main() {
    cin >> n;
    while (n)
        ret *= n--;
    cout << ret;
    return 0;
}