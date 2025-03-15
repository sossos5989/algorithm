#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long INF = 1e18 + 1;

int n;
long long k;
long long list[100010];
vector<int> lis;                         // O(n log n)으로 구할 때 lis 저장소
vector<vector<long long>> value(100010); // list[i,n)의 최대 LIS길이
vector<vector<int>> index(100010); // length의 특정 값이 나타나는 index를 정리
vector<vector<long long>> ways(1); // 각 length에 해당하는 경우의 수
vector<vector<pair<int, int>>> ptr(1); // 다음 단계의 ptr
vector<vector<long long>> seg(1); // 경우의 수를 쿼리하기 위한 세그먼트 트리
vector<vector<long long>> new_ways(1);     // 중복 처리를 한 새로운 경우의 수
vector<vector<pair<int, int>>> new_ptr(1); // 다음 단계의 ptr

// make SegmentTree
long long init(int node, int start, int end, vector<long long> &ori,
               vector<long long> &tree) {
    int mid = (start + end) / 2;
    if (start == end) return tree[node] = ori[start];
    long long cand = init(node * 2, start, mid, ori, tree) +
                     init(node * 2 + 1, mid + 1, end, ori, tree);
    return tree[node] = min(cand, INF);
}

// RSQ
long long query(int node, int start, int end, int left, int right,
                vector<long long> &tree) {
    if (left > end || right < start || left > right) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    long long cand = query(node * 2, start, mid, left, right, tree) +
                     query(node * 2 + 1, mid + 1, end, left, right, tree);
    return min(cand, INF);
}

void updateWays(int k, int i, int j) {
    if (i > lis.size()) return;
    if (k == 1) return;
    long long cand = ways[i][j] * k;
    if (cand / k != ways[i][j]) cand = INF;
    ways[i][j] = cand;
    int start = ptr[i][j].first, end = ptr[i][j].second;
    for (int idx = start; idx <= end; idx++) {
        updateWays(k, i + 1, idx);
    }
}

int main() {
    fastIO;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    for (int i = 0; i < n; i++) {
        long long &cand = list[i];
        auto it = lower_bound(lis.begin(), lis.end(), cand);
        if (it == lis.end()) {
            lis.push_back(cand);
            value[lis.size()].push_back(cand);
            index[lis.size()].push_back(i);
        } else {
            *it = cand;
            value[it - lis.begin() + 1].push_back(cand);
            index[it - lis.begin() + 1].push_back(i);
        }
    }

    value.resize(lis.size() + 1);
    index.resize(lis.size() + 1);
    ways.resize(lis.size() + 1);
    seg.resize(lis.size() + 1);
    ptr.resize(lis.size() + 1);
    new_ways.resize(lis.size() + 1);
    new_ptr.resize(lis.size() + 1);

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
                                value[i][j], greater<long long>()) -
                    value[i + 1].begin() - 1;

            long long cand =
                query(1, 0, ways[i + 1].size() - 1, a, b, seg[i + 1]);
            ways[i].push_back(cand);
            ptr[i].push_back({a, b});
        }

        // ways를 만들었으니 세그트리를 만들자
        seg[i].resize(ways[i].size() * 4, 0LL);
        init(1, 0, ways[i].size() - 1, ways[i], seg[i]);
    }

    // new_ways 중복제거 <- 이 로직이 개 어려워서 다시 만들거나 해야할듯 ??
    for (int i = 1; i <= lis.size(); i++) {
        long long prev = value[i][0];
        vector<int> times(lis.size(), 0);
        count.push_back(prev);
        for (int j = 1; j < value[i].size(); j++) {
            if (prev != value[i][j]) {
                prev = value[i][j];
            } else {
            }
        }
    }

    if (query(1, 0, new_ways[1].size() - 1, 0, new_ways[1].size() - 1, seg[1]) <
        k)
        cout << "-1";
    else {
        int lo = 0, hi = new_ways[1].size() - 1;
        for (int i = 1; i <= lis.size(); i++) {
            for (; hi >= lo; hi--) {
                if (k > new_ways[i][hi])
                    k -= new_ways[i][hi];
                else {
                    cout << value[i][hi] << " ";
                    if (i == lis.size()) break;
                    lo = ptr[i][hi].first;
                    hi = ptr[i][hi].second;
                    break;
                }
            }
        }
    }
    return 0;
}
