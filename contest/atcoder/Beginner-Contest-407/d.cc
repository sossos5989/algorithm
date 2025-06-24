#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int h, w;
long long list[21][21];
long long ans = 0;

long long backtrack(int bitmask, long long curXor) {
    long long best = curXor;

    for (int i = 0; i < h * w - 1; i++) {
        if (i % w == w - 1) continue;
        if ((bitmask & (1 << i)) == 0 && (bitmask & (1 << (i + 1))) == 0) {
            int nb = bitmask | (1 << i) | (1 << (i + 1));
            long long xor2 =
                list[i / w][i % w] ^ list[(i + 1) / w][(i + 1) % w];
            best = max(best, backtrack(nb, curXor ^ xor2));
        }
    }

    for (int i = 0; i < h * w; i++) {
        if (i + w >= h * w) continue;
        if ((bitmask & (1 << i)) == 0 && (bitmask & (1 << (i + w))) == 0) {
            int nb = bitmask | (1 << i) | (1 << (i + w));
            long long xor2 =
                list[i / w][i % w] ^ list[(i + w) / w][(i + w) % w];
            best = max(best, backtrack(nb, curXor ^ xor2));
        }
    }

    return best;
}

int main() {
    fastIO;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> list[i][j];
            ans ^= list[i][j];
        }
    }
    cout << backtrack(0, ans);
    return 0;
}