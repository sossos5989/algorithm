#include <algorithm>
#include <iostream>
#include <math.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, list[500000], repeat[9000], sum, lo = 4000, hi = -4000;

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
        sum += list[i];
        lo = min(lo, list[i]);
        hi = max(hi, list[i]);
        repeat[list[i] + 4000]++;
    }

    // 이걸 쓰지 않고 구할 수 있다. 굳이 정렬이 필요한가?
    sort(list, list + n);

    int max = 0, index = -1;
    bool condi = false;
    for (int i = 0; i < 9000; i++) {
        if (max < repeat[i]) {
            condi = true;
            max = repeat[i];
            index = i - 4000;
        } else if (condi && max == repeat[i]) {
            index = i - 4000;
            condi = false;
        }
    }
    cout << (int)round((double)sum / n) << "\n";
    cout << round(list[n / 2]) << "\n";
    cout << index << "\n";
    cout << hi - lo << "\n";
    return 0;
}