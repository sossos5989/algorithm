#include <iostream>
#include <string>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int cache, ret, repeat = 5;

int main() {
    fastIO;
    while (repeat--) {
        cin >> cache;
        ret += cache * cache;
    }
    cout << ret % 10 << endl;
    return 0;
}