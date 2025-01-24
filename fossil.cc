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
        if (block1[i].x < block1[(i + 1) % n].x)
            lower.push_back(make_pair(block1[i], block1[(i + 1) % n]));
        else if (block1[i].x > block1[(i + 1) % n].x)
            upper.push_back(make_pair(block1[i], block1[(i + 1) % n]));
    }
    for (int i = 0; i < m; i++) {
        if (block2[i].x < block2[(i + 1) % m].x)
            lower.push_back(make_pair(block2[i], block2[(i + 1) % m]));
        else if (block2[i].x > block2[(i + 1) % m].x)
            upper.push_back(make_pair(block2[i], block2[(i + 1) % m]));
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
double function(const coord &a, const coord &b, double x) {
    return a.y + (b.y - a.y) * (x - a.x) / (b.x - a.x);
}

// g(x) - f(x)를 구하는 함수
double gap(double x) {
    double minUp = 1e5, maxLow = -1e5;
    for (int i = 0; i < upper.size(); i++) {
        if (between(upper[i].first, upper[i].second, x))
            minUp = min(minUp, function(upper[i].first, upper[i].second, x));
    }
    for (int i = 0; i < lower.size(); i++) {
        if (between(lower[i].first, lower[i].second, x))
            maxLow = max(maxLow, function(lower[i].first, lower[i].second, x));
    }
    return minUp - maxLow;
}

double optimize() {
    double lo = max(block1MinX, block2MinX), hi = min(block1MaxX, block2MaxX);
    if (hi < lo) return 0.0;
    int it = 100;

    while (it--) {
        double aab = (lo * 2 + hi) / 3.0;
        double abb = (lo + hi * 2) / 3.0;
        double gapA = gap(aab);
        double gapB = gap(abb);
        if (gapA < gapB)
            lo = aab;
        else
            hi = abb;
    }

    return max(0.0, gap(hi));
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

        cout << optimize() << endl;
    }
    return 0;
}
