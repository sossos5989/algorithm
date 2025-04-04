#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long INF = 1e18;

int n;
long long k;
long long list[100010];
vector<int> lis;                         // O(n log n)으로 구할 때 lis 저장소
vector<vector<long long>> value(100010); // list[i,n)의 최대 LIS길이
vector<vector<int>> index(100010); // length의 특정 값이 나타나는 index를 정리
vector<vector<long long>> ways(1); // 각 length에 해당하는 경우의 수
vector<vector<pair<int, int>>> ptr(1); // 다음 단계의 ptr
vector<vector<long long>> seg(1); // 경우의 수를 쿼리하기 위한 세그먼트 트리
vector<long long> vec;            // 이 단계에서 이것의 개수.. 몇 번 반복하는지
vector<long long> cache;          // 다음 단계의 곱을 위한 것

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

    if (query(1, 0, ways[1].size() - 1, 0, ways[1].size() - 1, seg[1]) < k) {
        cout << -1;
        return 0;
    }

    // k번째 LIS를 구한다.
    vec.assign(ways[1].size(), 1);

    for (int i = 1; i < lis.size(); i++) {
        int hi = ways[i].size() - 1;
        long long now = value[i][hi];
        long long sz = ways[i][hi] * vec[hi];
        if (vec[hi] && ways[i][hi] && sz / vec[hi] != ways[i][hi]) sz = INF;

        // 차분 배열 세팅
        cache.assign(ways[i + 1].size() + 1, 0);
        if (ptr[i][hi].first <= ptr[i][hi].second) {
            cache[ptr[i][hi].first] += vec[hi];
            cache[ptr[i][hi].second + 1] -= vec[hi];
        }

        for (int elem = ways[i].size() - 2; elem >= 0; elem--) {
            long long cand = ways[i][elem] * vec[elem];
            if (vec[elem] != 0 && ways[i][elem] != 0 &&
                (cand / vec[elem] != ways[i][elem]))
                cand = INF;

            if (value[i][elem] == now) {
                sz = min(INF, sz + cand);

                // 차분 배열 세팅
                if (ptr[i][elem].first <= ptr[i][elem].second) {
                    cache[ptr[i][elem].first] += vec[elem];
                    if (cache[ptr[i][elem].first] < 0)
                        cache[ptr[i][elem].first] = 9 * INF;
                    cache[ptr[i][elem].second + 1] -= vec[elem];
                    if (cache[ptr[i][elem].second + 1] > 0)
                        cache[ptr[i][elem].second + 1] = -9 * INF;
                }

            } else {
                if (k > sz) {
                    // k를 감소시킬 수 있음. 이전 원소와 현재 원소를 업데이트
                    long long prevv = now;
                    now = value[i][elem];

                    k -= sz; // 감소 수행

                    // sz를 새로운 것으로 업데이트
                    sz = ways[i][elem] * vec[elem];
                    if (vec[elem] != 0 && ways[i][elem] != 0 &&
                        sz / vec[elem] != ways[i][elem])
                        sz = INF;

                    // cache 초기화를 수행한다.
                    for (int xx = elem + 1;
                         xx < ways[i].size() && value[i][xx] == prevv; xx++) {
                        if (ptr[i][xx].first <= ptr[i][xx].second) {
                            cache[ptr[i][xx].first] = 0;
                            cache[ptr[i][xx].second + 1] = 0;
                        }
                    }

                    // 차분 배열 세팅
                    if (ptr[i][elem].first <= ptr[i][elem].second) {
                        cache[ptr[i][elem].first] = vec[elem];
                        cache[ptr[i][elem].second + 1] = -vec[elem];
                    }
                } else {
                    // k 감소 불가. 현재 상태의 now와 cache를 들고 간다.
                    break;
                }
            }
        }

        // 원소를 출력한다.
        cout << now << " ";

        // 다음 단계를 준비한다..
        vec.assign(ways[i + 1].size(), 0);

        // 차분 배열
        vec[0] = cache[0];
        for (int p = 1; p < ways[i + 1].size(); p++) {
            vec[p] = vec[p - 1] + cache[p];
            if (INF - vec[p - 1] < cache[p]) vec[p] = INF;
        }
    }

    // 마지막 LIS의 원소에 대해 수행..
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (k > vec[i]) {
            k -= vec[i];
        } else {
            cout << value[lis.size()][i];
            break;
        }
    }

    // cout << '\n';
    // for (auto &&i : vec) {
    //     cout << i << " ";
    // }

    return 0;
}
