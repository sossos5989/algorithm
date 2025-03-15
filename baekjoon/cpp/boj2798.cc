#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, list[100], sum;

int main() {
    fastIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int cand = list[i] + list[j] + list[k];
                if (cand <= m) sum = max(sum, cand);
            }
        }
    }
    cout << sum;
    return 0;
} // 귀찮아서 무지성 브루트포스