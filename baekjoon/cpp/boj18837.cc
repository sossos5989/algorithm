#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long INF = 1e18 + 1;

int n;
long long k;
int list[100010];
vector<pair<int, int>> new_list;
vector<int> lis; // O(n log n)으로 구할 때 lis 저장소
int length[100010];
vector<vector<int>> value(100010);  // list[i,n)의 최대 LIS길이
vector<vector<int>> repeat(100010); // 연속으로 몇 번 등장함 ?
vector<vector<int>> index(100010);  // length의 특정 값이 나타나는 index를 정리
vector<vector<long long>> ways(1);  // 각 length에 해당하는 경우의 수
vector<vector<long long>> seg(1);   // 경우의 수를 쿼리하기 위한 세그먼트 트리
vector<vector<pair<int, int>>> ptr(1); // 다음 단계의 ptr

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

    // list를 기반으로 압축, 같은 수가 나오면, *처리
    int prev = list[0], times = 1;
    for (int i = 1; i < n; i++) {
        if (list[i] == prev)
            times++;
        else {
            new_list.push_back({prev, times});
            prev = list[i];
            times = 1;
        }
    }
    new_list.push_back({prev, times});

    for (int i = 0; i < new_list.size(); i++) {
        auto &cand = new_list[i];
        auto it = lower_bound(lis.begin(), lis.end(), cand.first);
        if (it == lis.end()) {
            lis.push_back(cand.first);
            length[i] = lis.size();
        } else {
            *it = cand.first;
            length[i] = it - lis.begin() + 1;
        }
    }

    value.resize(lis.size() + 1);
    index.resize(lis.size() + 1);
    repeat.resize(lis.size() + 1);
    ways.resize(lis.size() + 1);
    seg.resize(lis.size() + 1);
    ptr.resize(lis.size() + 1);

    for (int i = 0; i < new_list.size(); i++) {
        value[length[i]].push_back(new_list[i].first);
        repeat[length[i]].push_back(new_list[i].second);
        index[length[i]].push_back(i);
    }

    // for (auto &i : value) {
    //     for (auto &j : i) {
    //         cout << "(" << j.first << "," << j.second << ")";
    //     }
    //     cout << "\n";
    // }

    // value[lis.size()].push_back(cand);
    // index[lis.size()].push_back(count++);
    // value[it - lis.begin() + 1].push_back(cand);
    // index[it - lis.begin() + 1].push_back(count++);

    // base, ways와 이를 기반으로 한 SegmentTree 만들기
    for (int i = 0; i < value[lis.size()].size(); i++) {
        ways[lis.size()].push_back(repeat[lis.size()][i]);
        ptr[lis.size()].push_back({1, 0});
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
            long long ans = cand;
            ways[i].push_back(ans);
            ptr[i].push_back({a, b});
            updateWays(repeat[i][j], i, j);
        }

        // ways를 만들었으니 세그트리를 만들자
        seg[i].resize(ways[i].size() * 4, 0LL);
        init(1, 0, ways[i].size() - 1, ways[i], seg[i]);
    }

    for (auto &i : ways) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }

    if (query(1, 0, ways[1].size() - 1, 0, ways[1].size() - 1, seg[1]) < k)
        cout << "-1";
    else {
        int lo = 0, hi = ways[1].size() - 1;
        for (int i = 1; i <= lis.size(); i++) {
            for (; hi >= lo; hi--) {
                if (k > ways[i][hi])
                    k -= ways[i][hi];
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
