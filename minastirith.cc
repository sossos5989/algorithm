#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// 일단 맨 처음 큰 원을 고름.
// 그러면 이 원과 맞닿는 원중 남은 원의 둘레를 더 많이 표현할 수 있는 원을 선택
// 이를 반복

// angle, left, right는 [0, 2]사이의 실수
struct Circle {
    double y, x, r, mid, left, right;
    void compute() {
        mid = atan2(x, y);
        double delta = acos(1.0 - (r * r) / 128.0);
        left = mid - delta;
        right = mid + delta;
        if (mid < 0) mid += 2 * M_PI;
        if (left < 0) left += 2 * M_PI;
        if (right < 0) right += 2 * M_PI;
        mid /= M_PI;
        left /= M_PI;
        right /= M_PI;
    }
};

bool compare(const Circle &a, const Circle &b) { return a.mid < b.mid; }

int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat--) {
        int n;
        cin >> n;
        vector<Circle> list(n); // y, x, r
        for (int i = 0; i < n; i++) {
            cin >> list[i].y >> list[i].x >> list[i].r;
            list[i].compute();
        }

        // 가장 큰 원을 처음으로, 중점을 시계방향으로 정렬시킵니다.
        sort(list.begin(), list.end(), compare);
        int cache = -1, pivot = -1;
        for (int i = 0; i < n; i++) {
            if (list[i].r > cache) {
                cache = list[i].r;
                pivot = i;
            }
        }
        rotate(list.begin(), list.begin() + pivot, list.end());

        double deltaCheck = acos(1.0 - (list[0].r * list[0].r) / 128.0);
        if (deltaCheck >= M_PI) {
            cout << 1 << "\n";
            continue; // 다음 테스트케이스로
        }

        double leftPoint = list[0].left;
        double rightPoint = list[0].right;

        int used = 1;
        bool impossible = false;

        return 0;
    }
