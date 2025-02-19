#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, m, b, cache, count[257] = {0};
    cin >> n >> m >> b;
    for (int i = 0; i < n * m; i++) {
        cin >> cache;
        count[cache]++;
    }

    int time = 50000000, height = -1;
    for (int h = 256; h >= 0; h--) {
        int need = 0, gain = 0;
        for (int i = 0; i < h; i++) {
            need += (h - i) * count[i];
        }
        for (int j = 256; j > h; j--) {
            gain += (j - h) * count[j];
        }
        int cand = need + gain * 2;
        if (need <= gain + b && time > cand) {
            time = cand;
            height = h;
        }
    }
    cout << time << " " << height;
    return 0;
}