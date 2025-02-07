#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, cache;
int list[10001];
int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cache;
        list[cache]++;
    }
    for (int i = 1; i <= 10000; i++) {
        while (list[i]--) {
            cout << i << "\n";
        }
    }
    return 0;
} // 대충 sort하면 안된다.