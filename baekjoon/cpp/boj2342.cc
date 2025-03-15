#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int DP[100000][16];

int main() {
    fastIO;
    int n = 0, input = -1, list[100000];
    for (; input != 0; n++) {
        cin >> input;
        list[n] = input;
    }

    // init
    int first = -1, second = -1, ret = 0, i = 0;
    for (; i < n; i++) {
        if (first == list[i] || second == list[i]) {
            ret += 1;
        } else if (first == -1) {
            first = list[i];
            ret += 2;
        } else if (second == -1) {
            second = list[i];
            ret += 2;
        } else {
            break;
        }
    }

    int value = 0;
    value |= 1 << (first - 1);
    value |= 1 << (second - 1);
    for (int i = i; i < n; i++) {
        if (list[i] == 1) {
        }
    }
    cout << ret;

    return 0;
} // 공간 복잡도 미안..