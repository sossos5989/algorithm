#include <algorithm>
#include <iostream>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        int n, m, hi = 0, input;
        cin >> n >> m;
        int priority[10] = {0};
        queue<pair<int, int>> list;
        for (int i = 0; i < n; i++) {
            cin >> input;
            priority[input]++;
            hi = max(hi, input);
            list.push(make_pair(input, i));
        } // 전처리

        int count = 1;
        while (list.size()) {
            pair<int, int> cache = list.front();
            list.pop();
            if (cache.first == hi) {
                if (cache.second == m) {
                    break;
                } else {
                    priority[hi]--;
                    count++;
                    if (priority[hi] == 0) {
                        for (int i = hi - 1; i >= 0; i--) {
                            if (priority[i]) {
                                hi = i;
                                break;
                            }
                        }
                    }
                }
            } else {
                list.push(cache);
            }
        }
        cout << count << "\n";
    }
    return 0;
}