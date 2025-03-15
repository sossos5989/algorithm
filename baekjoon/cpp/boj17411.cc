#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long MOD = 1000000007;

int n;
long long k;
int list[1000010];
vector<int> lis;                    // O(n log n)으로 구할 때 lis 저장소
vector<vector<int>> value(1000001); // list[i,n)의 최대 LIS길이
vector<vector<int>> index(1000001); // length의 특정 값이 나타나는 index를 정리
vector<vector<long long>> ways(1);  // 각 length에 해당하는 경우의 수
vector<vector<long long>> seg(1);   // 경우의 수를 쿼리하기 위한 세그먼트 트리

// make SegmentTree
long long init(int node, int start, int end, vector<long long> &ori,
               vector<long long> &tree) {
    int mid = (start + end) / 2;
    if (start == end) return tree[node] = ori[start];
    long long cand = init(node * 2, start, mid, ori, tree) +
                     init(node * 2 + 1, mid + 1, end, ori, tree);
    return tree[node] = cand % MOD;
}

// RSQ
long long query(int node, int start, int end, int left, int right,
                vector<long long> &tree) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    long long cand = query(node * 2, start, mid, left, right, tree) +
                     query(node * 2 + 1, mid + 1, end, left, right, tree);
    return cand % MOD;
}

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    for (int i = 0; i < n; i++) {
        int &cand = list[i];
        auto it = lower_bound(lis.begin(), lis.end(), cand);
        if (it == lis.end()) {
            lis.push_back(cand);
            value[lis.size()].push_back(list[i]);
            index[lis.size()].push_back(i);
        } else {
            *it = cand;
            value[it - lis.begin() + 1].push_back(list[i]);
            index[it - lis.begin() + 1].push_back(i);
        }
    }

    value.resize(lis.size() + 2);
    index.resize(lis.size() + 2);
    ways.resize(lis.size() + 2);
    seg.resize(lis.size() + 2);

    // base, ways와 이를 기반으로 한 SegmentTree 만들기
    for (int i = 0; i < value[lis.size()].size(); i++) {
        ways[lis.size()].push_back(1);
    }

    seg[lis.size()].resize(ways[lis.size()].size() * 4, 0LL);
    init(1, 0, ways[lis.size()].size() - 1, ways[lis.size()], seg[lis.size()]);

    for (int i = lis.size() - 1; i >= 1; i--) {
        for (int j = 0; j < value[i].size(); j++) {
            // a부터 b사이
            int a = upper_bound(index[i + 1].begin(), index[i + 1].end(),
                                index[i][j]) -
                    index[i + 1].begin();
            int b = lower_bound(value[i + 1].begin(), value[i + 1].end(),
                                value[i][j], greater<int>()) -
                    value[i + 1].begin() - 1;

            long long cand =
                query(1, 0, ways[i + 1].size() - 1, a, b, seg[i + 1]);
            ways[i].push_back(cand);
        }

        // ways를 만들었으니 세그트리를 만들자
        seg[i].resize(ways[i].size() * 4, 0LL);
        init(1, 0, ways[i].size() - 1, ways[i], seg[i]);
    }

    cout << lis.size() << " "
         << query(1, 0, ways[1].size() - 1, 0, ways[1].size() - 1, seg[1]) %
                MOD;
    return 0;
}
