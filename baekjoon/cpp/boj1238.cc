#include <iostream>
#include <queue>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int INF = 123456789;
int n, m, x;

// graph의 각 vertex의 edge와 weight를 표현한다.
vector<vector<pair<int, int>>> graph;

vector<int> weight;

int answer[1001];

void dijkstra(int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    weight[k] = 0;
    pq.push(make_pair(0, k));

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();
        if (weight[cur_node] < cur_weight) continue;
        for (auto &edge : graph[cur_node]) {
            int next_node = edge.second;
            int new_dist = cur_weight + edge.first;

            if (new_dist < weight[next_node]) {
                weight[next_node] = new_dist;
                pq.push({new_dist, next_node});
            }
        }
    }
}

int main() {
    fastIO;
    cin >> n >> m >> x;
    graph.resize(n + 1);
    weight.assign(n + 1, INF);
    int start, end, w;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> w;
        graph[start].push_back(make_pair(w, end));
    }

    dijkstra(x);

    for (int i = 1; i <= n; i++) {
        answer[i] = weight[i];
    }

    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        weight.assign(n + 1, INF);
        dijkstra(i);
        answer[i] += weight[x];
    }

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = max(ret, answer[i]);
    }

    cout << ret << endl;
    return 0;
} // 아 몰랑 구현

// 정석은 역방향 그래프를 만들어서 다익스트라를 돌리면 된다.
// 그러면 O(E logN)시간이 나올 듯 ?
// 그냥 역방향 그래프를 안 만들고,
// 다익스트라를 n번 -> O(n^2 *log n)풀이이나 되긴 함. 수정해보자 나중에