#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int INF = 100000000;
int r[5000001];
vector<int> child[500001];

void updateRank(int node) {
    for (int &i : child[node]) {
        r[i] = r[node] + 1;
        updateRank(i);
    }
}

int idx = 0, tour[1000001], idxLo[500001], idxHi[500001];
void eulerTour(int node) {
    tour[idx] = r[node];
    if (idxLo[node] == 0 && node != 1) idxLo[node] = idx;
    idxHi[node] = idx;
    idx++;
    for (int i = 0; i < child[node].size(); i++) {
        eulerTour(child[node][i]);
        tour[idx] = r[node];
        if (idxLo[node] == 0 && node != 1) idxLo[node] = idx;
        idxHi[node] = idx;
        idx++;
    }
}

int segTree[4000001];
int init(int node, int left, int right) {
    if (left == right) return segTree[node] = tour[left];
    int mid = (left + right) / 2;
    return segTree[node] = min(init(node * 2, left, mid),
                               init(node * 2 + 1, mid + 1, right));
}

int query(int node, int left, int right, int arrLeft, int arrRight) {
    if (arrRight < left || right < arrLeft) return INF;
    if (arrLeft <= left && right <= arrRight) return segTree[node];
    int mid = (left + right) / 2;
    return min(query(node * 2, left, mid, arrLeft, arrRight),
               query(node * 2 + 1, mid + 1, right, arrLeft, arrRight));

} // RMQ

int main() {
    fastIO;
    int n, q, input, k;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> input;
        child[input].push_back(i);
    }

    updateRank(1);       // rank update with dfs
    eulerTour(1);        // eulerTour
    init(1, 0, idx - 1); // segment tree;

    while (q--) {
        vector<int> loList, hiList;
        cin >> k;
        while (k--) {
            cin >> input;
            loList.push_back(idxLo[input]);
            hiList.push_back(idxHi[input]);
        }

        sort(loList.begin(), loList.end());
        sort(hiList.begin(), hiList.end());
        // for (auto &&i : loList) {
        //     cout << i << ' ';
        // }
        // cout << '\n';
        // for (auto &&i : hiList) {
        //     cout << i << ' ';
        // }
        // cout << '\n';

        int sum = 0;
        for (int i = 0; i < hiList.size() - 1; i++) {
            sum += query(1, 0, idx - 1, hiList[i], hiList[i + 1]);
        }

        cout << sum << '\n';
    }

    return 0;
}