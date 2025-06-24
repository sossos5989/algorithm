#include <iostream>
using namespace std;

int main() {
    int n, k, cnt = 0;
    cin >> n >> k;
    for (int i = 0; i < 3600 * (n + 1); i++) {
        if (i % 10 == k || (i % 60) / 10 == k || (i / 60) % 10 == k ||
            ((i / 60) % 60) / 10 == k || (i / 3600) % 10 == k ||
            (i / 3600) / 10 == k)
            cnt++;
    }
    cout << cnt;
    return 0;
}