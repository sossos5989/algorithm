#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

static const int INF_MIN = -20001;
static const int INF_MAX = 20001;

pair<int, int> seg[1 << 18]; // {max, min}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        int n, q;
        cin >> n >> q;
        int power2 = 1;
        while (power2 < n)
            power2 <<= 1;
        for (int i = 0; i < (1 << 18); i++) {
            seg[i] = {INF_MIN, INF_MAX};
        }

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            seg[power2 + i] = {val, val};
        }

        for (int i = power2 - 1; i > 0; i--) {
            seg[i].first = max(seg[i << 1].first, seg[i << 1 | 1].first);
            seg[i].second = min(seg[i << 1].second, seg[i << 1 | 1].second);
        }

        function<pair<int, int>(int, int, int, int, int)> query =
            [&](int left, int right, int node, int nl,
                int nr) -> pair<int, int> {
            if (right < nl || left > nr) {
                return make_pair(INF_MIN, INF_MAX);
            }
            if (left <= nl && nr <= right) {
                return seg[node];
            }
            int mid = (nl + nr) >> 1;
            auto c1 = query(left, right, node << 1, nl, mid);
            auto c2 = query(left, right, node << 1 | 1, mid + 1, nr);
            return make_pair(max(c1.first, c2.first),
                             min(c1.second, c2.second));
        };

        while (q--) {
            int a, b;
            cin >> a >> b;
            auto ans = query(a, b, 1, 0, power2 - 1);
            cout << ans.first - ans.second << "\n";
        }
    }
    return 0;
}

// 내가 작성한 코드를 반복적 SegTree로 Ai 도움을 받아 수정해봄
// 놀랍게도 재귀적 방법이랑 동작시간이 똑같음 ㅋㅋ
