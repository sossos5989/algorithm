#include <cstring>
#include <iostream>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, input[100001][3];
int maxDp[2][3];
int minDp[2][3];

int main() {
    fastIO;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> input[i][j];
        }
    }

    memset(minDp, 0x7f, sizeof(minDp));
    maxDp[(n - 1) % 2][0] = minDp[(n - 1) % 2][0] = input[(n - 1)][0];
    maxDp[(n - 1) % 2][1] = minDp[(n - 1) % 2][1] = input[(n - 1)][1];
    maxDp[(n - 1) % 2][2] = minDp[(n - 1) % 2][2] = input[(n - 1)][2];

    for (int i = n - 2; i >= 0; i--) {
        maxDp[i % 2][0] =
            max(maxDp[(i + 1) % 2][0], maxDp[(i + 1) % 2][1]) + input[i][0];

        maxDp[i % 2][1] =
            max(maxDp[(i + 1) % 2][0],
                max(maxDp[(i + 1) % 2][1], maxDp[(i + 1) % 2][2])) +
            input[i][1];

        maxDp[i % 2][2] =
            max(maxDp[(i + 1) % 2][1], maxDp[(i + 1) % 2][2]) + input[i][2];

        minDp[i % 2][0] =
            min(minDp[(i + 1) % 2][0], minDp[(i + 1) % 2][1]) + input[i][0];

        minDp[i % 2][1] =
            min(minDp[(i + 1) % 2][0],
                min(minDp[(i + 1) % 2][1], minDp[(i + 1) % 2][2])) +
            input[i][1];

        minDp[i % 2][2] =
            min(minDp[(i + 1) % 2][1], minDp[(i + 1) % 2][2]) + input[i][2];
    }

    cout << max(maxDp[0][0], max(maxDp[0][1], maxDp[0][2])) << ' ';
    cout << min(minDp[0][0], min(minDp[0][1], minDp[0][2]));
    return 0;
} // 클론코딩했지만 개선할 수 있을 듯