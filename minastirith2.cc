#include <bits/stdc++.h>
using namespace std;

struct Circle {
    double y, x, r;
    // 각도 구간 [left, right] (라디안)
    double left, right;

    void compute() {
        double mid = atan2(x, y);
        if (mid < 0) mid += 2.0 * M_PI;

        double delta = acos(1.0 - (r * r) / 128.0);
        left = mid - delta;
        right = mid + delta;
        // [0, 2*pi] 범위로 보정
        if (left < 0) left += 2.0 * M_PI;
        if (right < 0) right += 2.0 * M_PI;
        if (left >= 2.0 * M_PI) left -= 2.0 * M_PI;
        if (right >= 2.0 * M_PI) right -= 2.0 * M_PI;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; // 테스트 케이스
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Circle> circles(n);

        // 입력 및 [left, right] 계산
        for (int i = 0; i < n; i++) {
            cin >> circles[i].y >> circles[i].x >> circles[i].r;
            circles[i].compute();
        }

        // 한 초소(원)가 180도 이상을 덮는다면 1명으로 가능 (delta >= pi)
        bool singleOk = false;
        for (int i = 0; i < n; i++) {
            double delta = acos(1.0 - (circles[i].r * circles[i].r) / 128.0);
            if (delta >= M_PI) {
                cout << 1 << "\n";
                singleOk = true;
                break;
            }
        }
        if (singleOk) continue;

        // ---------------------------------------------------------
        // 원형 구간(0~2*pi)을 덮기 위한 최소 초소 수
        // 모든 초소를 pivot으로 시도
        // ---------------------------------------------------------
        int answer = INT_MAX;

        for (int pivot = 0; pivot < n; pivot++) {
            // pivot의 left 각도를 0으로 맞추는 shift
            double shift = circles[pivot].left;

            // intervals 만들기
            // [L, R]를 shift해서 [0, 2*pi] 구간에 매핑
            //  (L - shift + 2*pi) mod 2*pi,  (R - shift + 2*pi) mod 2*pi
            // L > R일 경우, 원점을 넘나드는 구간이므로 분할
            vector<pair<double, double>> intervals;
            intervals.reserve(n * 2);

            for (int i = 0; i < n; i++) {
                double L = circles[i].left - shift;
                double R = circles[i].right - shift;
                // mod 2*pi
                L = fmod(L + 2.0 * M_PI, 2.0 * M_PI);
                R = fmod(R + 2.0 * M_PI, 2.0 * M_PI);

                if (L <= R) {
                    intervals.push_back({L, R});
                } else {
                    // 원점을 통과하는 구간 => [0,R], [L,2*pi]
                    intervals.push_back({0.0, R});
                    intervals.push_back({L, 2.0 * M_PI});
                }
            }

            // intervals를 left 오름차순 정렬
            sort(intervals.begin(), intervals.end());

            // 여기서부터 coverCircle() 없이 직접 그리디 로직
            double coverage = 0.0; // 현재 덮인 구간의 끝
            int used = 0;
            int idx = 0;
            int m = (int)intervals.size();

            bool fail = false;
            while (coverage < 2.0 * M_PI) {
                double bestExtend = coverage;

                // coverage 이하에서 시작하는 (left <= coverage) 구간 중
                // right가 가장 큰 것 선택
                bool found = false;
                while (idx < m && intervals[idx].first <= coverage) {
                    found = true;
                    bestExtend = max(bestExtend, intervals[idx].second);
                    idx++;
                }
                // 확장 못 하면 실패
                if (!found || bestExtend == coverage) {
                    fail = true;
                    break;
                }
                used++;
                coverage = bestExtend;

                if (coverage >= 2.0 * M_PI) break;
            }

            if (!fail) {
                answer = min(answer, used);
            }
        }

        if (answer == INT_MAX) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << answer << "\n";
        }
    }
    return 0;
}
