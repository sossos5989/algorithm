#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, diameter;

struct circle {
    int x, y, r;
    bool operator<(const circle &other) const { return r > other.r; }
} circle[100];

vector<int> node[100];

bool isContained(int a, int b) {
    int dx = circle[a].x - circle[b].x;
    int dy = circle[a].y - circle[b].y;
    int dr = circle[a].r - circle[b].r;
    return dr > 0 && dx * dx + dy * dy <= dr * dr;
} // 원 a안에 b가 포함됨?

// node i의 edge를 채우는 함수
void makeNode(int i, int idx) {
    for (int &edge : node[i]) {
        if (isContained(edge, idx)) {
            makeNode(edge, idx);
            return;
        }
    }
    node[i].push_back(idx);
}

int height(int curr) {
    int best = 0, secondBest = 0;
    for (int next : node[curr]) {
        int h = height(next);
        if (h > best) {
            secondBest = best;
            best = h;
        } else if (h > secondBest) {
            secondBest = h;
        }
    }
    diameter = max(diameter, best + secondBest);
    return best + 1;
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> circle[i].x >> circle[i].y >> circle[i].r;
        }
        sort(circle, circle + n); // 반지름 오름차순 정렬
        for (int i = 0; i < n; i++) {
            node[i].clear();
        } // init()

        for (int i = 1; i < n; i++) {
            makeNode(0, i);
        } // node간의 연결 구현
        diameter = 0;
        height(0);
        cout << diameter << "\n";
    }
    return 0;
}