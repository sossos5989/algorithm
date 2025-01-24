#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
double block1MinX, block2MinX, block1MaxX, block2MaxX;

struct coord {
    double x, y;
};

vector<coord> block1(100); // n
vector<coord> block2(100); // m

vector<pair<coord, coord>> upper, lower; // 선분들(좌표 2개)을 저장합니다.

// 전처리함수
void initData() {
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (block1[i].x < block1[j].x)
            lower.push_back({block1[i], block1[j]});
        else if (block1[i].x > block1[j].x)
            upper.push_back({block1[i], block1[j]});
    }

    for (int i = 0; i < m; i++) {
        int j = (i + 1) % m;
        if (block2[i].x < block2[j].x)
            lower.push_back({block2[i], block2[j]});
        else if (block2[i].x > block2[j].x)
            upper.push_back({block2[i], block2[j]});
    }

    block1MinX = block1MaxX = block1[0].x;
    for (int i = 1; i < n; i++) {
        block1MinX = min(block1MinX, block1[i].x);
        block1MaxX = max(block1MaxX, block1[i].x);
    }

    block2MinX = block2MaxX = block2[0].x;
    for (int i = 1; i < m; i++) {
        block2MinX = min(block2MinX, block2[i].x);
        block2MaxX = max(block2MaxX, block2[i].x);
    }
}

// coordinate의 x좌표 사이에 존재하는지 구하는 함수
bool between(const coord &a, const coord &b, double x) {
    return (a.x <= x && x <= b.x) || (b.x <= x && x <= a.x);
}

// 두 정점을 잇는 f(x)와 x좌표가 주어지면 f(x)를 구하는 함수
double lineFunction(const coord &a, const coord &b, double x) {
    // 수직선(분모=0) 처리 가능성
    if (fabs(b.x - a.x) < 1e-12) {
        return a.y; // x == a.x 가정
    }
    return a.y + (b.y - a.y) * (x - a.x) / (b.x - a.x);
}

// g(x) - f(x)를 구하는 함수
double gap(double x) {
    double minUp = 1e9, maxLow = -1e9;
    bool foundUp = false, foundLow = false;

    // upper
    for (auto &seg : upper) {
        if (between(seg.first, seg.second, x)) {
            foundUp = true;
            double y = lineFunction(seg.first, seg.second, x);
            minUp = min(minUp, y);
        }
    }
    // lower
    for (auto &seg : lower) {
        if (between(seg.first, seg.second, x)) {
            foundLow = true;
            double y = lineFunction(seg.first, seg.second, x);
            maxLow = max(maxLow, y);
        }
    }

    // 만약 up / low 중 하나도 선분이 없다면 교집합 없음
    if (!foundUp || !foundLow) return 0.0;

    // 교집합 영역이 음수가 되면 0
    double ret = minUp - maxLow;
    return (ret > 0) ? ret : 0.0;
}

double optimize() {
    double lo = max(block1MinX, block2MinX);
    double hi = min(block1MaxX, block2MaxX);
    if (hi < lo) return 0.0;

    double bestVal = 0.0;
    int it = 100; // 반복 횟수
    while (it--) {
        double aab = (2.0 * lo + hi) / 3.0;
        double abb = (lo + 2.0 * hi) / 3.0;
        double gapA = gap(aab);
        double gapB = gap(abb);

        // 반복 과정 중에도 최댓값을 갱신
        bestVal = max(bestVal, max(gapA, gapB));

        if (gapA < gapB)
            lo = aab;
        else
            hi = abb;
    }
    return bestVal;
}

int main() {
    fastIO;
    int T;
    cin >> T;
    cout.precision(15);
    cout << fixed;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> block1[i].x >> block1[i].y;
        }
        for (int i = 0; i < m; i++) {
            cin >> block2[i].x >> block2[i].y;
        }
        upper.clear();
        lower.clear();
        initData();

        double ans = optimize();
        cout << ans << "\n";
    }
    return 0;
}
