#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int m, n;
    int list[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = 0; k < n; k++) {
                for (int p = k + 1; p < n; p++) {
                    // 대충 그 구간의 합을 구하는 ..
                }
            }
        }
    }

    return 0;
}