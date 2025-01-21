#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k;

struct info {
    int L; // 처음부터 도시까지의 거리
    int M; // 미터 전부터 표지판 표시
    int G; // 표지판의 간격
} city[5000];

// Distance 내에 있는 표지판의 개수를 파악하는 함수, 완전 탐색
bool findK(int dis) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int dL = city[i].L - city[i].M;
        if (dis >= dL) ret += (min(dis, city[i].L) - dL) / city[i].G + 1;
    }
    return ret >= k;
}

// findK를 이용해 이분탐색
int binarySearch() {
    int lo = 0, hi = 8030000;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (findK(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main() {
    fastIO;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> city[i].L >> city[i].M >> city[i].G;
        }
        cout << binarySearch() << endl;
    }

    return 0;
}