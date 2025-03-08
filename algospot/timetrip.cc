#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int INF = 2 * 1e9;
int g, w;
vector<vector<pair<int, int>>> adj; // 방향 그래프의 도착점, weight
int upper[101], lower[101];

int main() {
    fastIO;
    int c;
    cin >> c;
    while (c--) {
        // 입력, 전처리
        cin >> g >> w;
        int a, b, d;
        adj.assign(g + 1, {});
        while (w--) {
            cin >> a >> b >> d;
            adj[a].push_back(make_pair(b, d));
        }

        // 초기화
        upper[0] = lower[0] = 0;
        for (int i = 1; i < g; i++) {
            upper[i] = INF;
            lower[i] = -INF;
        }

        // Bellman-Ford algorithm
        bool isUpperChanged, isLowerChanged;
        for (int iter = 0; iter < g; iter++) {
            isUpperChanged = false, isLowerChanged = false;
            for (int i = 0; i < g; i++) {
                for (auto &j : adj[i]) {
                    int node = j.first;
                    int weight = j.second;
                    int candUpper = upper[i] + weight;
                    int candLower = lower[i] + weight;
                    if (upper[i] != INF && candUpper < upper[node]) {
                        upper[node] = candUpper;
                        isUpperChanged = true;
                    }
                    if (lower[i] != -INF && candLower > lower[node]) {
                        lower[node] = candLower;
                        isLowerChanged = true;
                    }
                }
            }
            if (!isUpperChanged && !isLowerChanged) break;
        }

        // 출력
        if (upper[1] == INF) {
            cout << "UNREACHABLE\n";
        } else {
            if (isUpperChanged)
                cout << "INFINITY ";
            else
                cout << upper[1] << " ";
            if (isLowerChanged)
                cout << "INFINITY\n";
            else
                cout << lower[1] << "\n";
        }
    }
    return 0;
}

// bellman-ford 알고리즘이 음수 사이클을 판별하는 것은 맞으나, 경로상에서 음수
// 사이클이 존재하는지 확인해야함.
// 따라서 사이클이 발생(값의 변동이 발생)한 edge를 (u,v)라고 하면,
// 0 -> ... v ... -> 1 를 잇는 edge가 존재해야 INF임을 알 수 있다.
