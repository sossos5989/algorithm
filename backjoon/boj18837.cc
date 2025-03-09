#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k;
int list[100001];
vector<vector<int>> value(100000); // list[i,n)의 최대 LIS길이
vector<vector<int>> index(100000); // length의 특정 값이 나타나는 index를 정리
vector<int> lis;

int main() {
    // fastIO;
    cin >> n >> k;
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

    vector<vector<long long>> ways(lis.size() + 1);
    vector<vector<long long>> psum(lis.size() + 1); // 부분합

    for (int i = 0; i < index[lis.size()].size(); i++) {
        psum[lis.size()].push_back(i + 1);
    }

    for (int i = lis.size() - 1; i >= 1; i--) {
        for (int j = 0; j < value[i].size(); j++) {
            // value[i][j], // 이분탐색 ...
            // index[i][j], // 이분 탐색...
            int a = upper_bound(value[i + 1].begin(), value[i + 1].end(),
                                value[i][j], greater<int>()) -
                    value[i + 1].begin();

            int b = upper_bound(index[i + 1].begin(), index[i + 1].end(),
                                index[i][j]) -
                    index[i + 1].begin();

            // b ~ a-1까지의 범위 !!

            // a = 0이면, 그냥 size 0임
            // b = size + 1이면, 이것도 size 0;

            if (a == 0 || b == index[i + 1].size() + 1 || b > a - 1)
                ways[i].push_back(0);
            else {
                // 오버플로우 처리할 것
                long long cand = psum[i + 1][a - 1];
                if (b != 0) cand -= psum[i + 1][b - 1];
                ways[i].push_back(cand);
            }
        }

        psum[i].push_back(ways[i][0]);
        for (int j = 1; j < ways[i].size(); j++) {
            psum[i].push_back(ways[i][j] + psum[i][j - 1]);
        }
    }

    for (auto &&i : psum) {
        for (auto &&j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
