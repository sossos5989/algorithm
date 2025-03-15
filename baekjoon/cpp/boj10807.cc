#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, cache, count[201];

int main() {
    fastIO;
    cin >> n;
    while (n--) {
        cin >> cache;
        count[cache + 100]++;
    }
    cin >> cache;
    cout << count[cache + 100];
    return 0;
}