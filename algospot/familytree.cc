#include <cstring>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, q, input, first[100000], d[100000], eularTour[200000], seg[200000 * 4];
vector<vector<int>> tree;

int idx;
void dfs(int node, int depth) {
    if (first[node] == -1) first[node] = idx;
    eularTour[idx++] = depth;
    d[node] = depth;
    if (!tree[node].empty()) {
        for (int &i : tree[node]) {
            dfs(i, depth + 1);
            eularTour[idx++] = depth;
        }
    }
} // dfs 탐색, 깊이 계산, eular Tour에서 노드의 첫 번째 index가 위치하는 곳 탐색

int segTreeInit(int node, int nl, int nr) {
    if (nl == nr) return seg[node] = eularTour[nl];
    int mid = (nl + nr) / 2;
    int left = segTreeInit(node * 2, nl, mid);
    int right = segTreeInit(node * 2 + 1, mid + 1, nr);
    return seg[node] = min(left, right);
}

int query(int start, int end, int node, int nl, int nr) {
    if (nr < start || end < nl) return 100001;
    if (start <= nl && nr <= end) return seg[node];
    int mid = (nl + nr) / 2;
    return min(query(start, end, node * 2, nl, mid),
               query(start, end, node * 2 + 1, mid + 1, nr));
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n >> q;
        tree.assign(n, {}); // tree 초기화는 이렇게 !!
        memset(first, -1, sizeof(int) * n);
        for (int i = 1; i < n; i++) {
            cin >> input;
            tree[input].push_back(i);
        }
        idx = 0;
        dfs(0, 0);
        segTreeInit(1, 0, 2 * n - 3);
        while (q--) {
            int a, b, aa, bb, lcaDepth;
            cin >> a >> b;
            aa = first[a], bb = first[b];
            if (aa > bb) swap(aa, bb);
            lcaDepth = query(aa, bb, 1, 0, 2 * n - 3);
            cout << d[a] + d[b] - 2 * lcaDepth << "\n";
        }
    }
    return 0;
}

// 1. 트리를 만든다
// 2. 전위 순회(DFS)를 해서 Eular Tour를 함
// 3. Eular Tour에서 노드 u, v가 첫 등장하는 시점의 구간 미리 구해놈
// 이 사이에는 무조건 LCA가 존재하며, 그보다 depth가 작은 조상은 존재하지 않음.
// 4. eularTour[First[u],First[v]] 구간에 대해
// 세그먼트 트리를 써서 depth의 최솟값을 구함.
// 5. 트리에서 각 노드에 저장된 depth..를 통해 연산