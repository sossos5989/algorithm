#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, input;
    cin >> n;
    int ans = 0, cnt = 0;
    while (n--) {
        cin >> input;
        if (input)
            cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    cout << max(ans, cnt);
    return 0;
}