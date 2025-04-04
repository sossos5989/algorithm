#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    string a, b;
    cin >> n >> a >> b;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) count++;
    }
    cout << count;
    return 0;
}