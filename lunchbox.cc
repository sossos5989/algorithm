#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// 스케쥴링 문제
// 결국 microwave에서 뎁히는 시간은 모든 경우가 동잏함
// 그러면 마지막에 먹는 사람이 엄청 빨리 먹는 사람이면 됨.
// 먹는 시간이 길 수록 빨리 데워주면 된다!
int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat--) {
        int n;
        cin >> n;
        vector<pair<int, int>> list(n); // First: eat, Second: microwave
        for (int i = 0; i < n; i++) {
            cin >> list[i].second;
        }
        for (int i = 0; i < n; i++) {
            cin >> list[i].first;
        }

        sort(list.begin(), list.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        });

        int sum = 0, ret = 0;
        for (int i = 0; i < n; i++) {
            sum += list[i].second;
            ret = max(ret, sum + list[i].first);
        }

        cout << ret << endl;
    }
    return 0;
}