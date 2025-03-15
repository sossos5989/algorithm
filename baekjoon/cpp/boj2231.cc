#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, cache, sum, answer;

int main() {
    fastIO;
    cin >> n;
    for (int i = max(1, n - 54); i < n; i++) {
        cache = sum = i;
        while (cache) {
            sum += cache % 10;
            cache /= 10;
        }
        if (sum == n) {
            answer = i;
            break;
        };
    }
    cout << answer;
    return 0;
}