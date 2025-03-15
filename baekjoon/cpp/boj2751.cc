#include <algorithm>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, list[1000000];
int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    sort(list, list + n);
    for (int i = 0; i < n; i++) {
        cout << list[i] << "\n";
    }

    return 0;
}