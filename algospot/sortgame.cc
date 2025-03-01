#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int factorial[9];
void initFactorial() {
    factorial[0] = 1;
    for (int i = 1; i < 9; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

int vecToState(const vector<int> &v) {
    int mask = 255, ret = 0;
    for (int i = 0; i < v.size(); i++) {
        // 지금 이 수가 몇번째 수인가?
        int count = 0;
        for (int j = 0; j < v[i] - 1; j++) {
            if (mask & (1 << j)) count++;
        }
        ret += count * factorial[v.size() - i - 1];
        mask &= ~(1 << (v[i] - 1));
    }
    return ret;
} // Lehmer 코드 변환 O(n^2), Query로 변환하면 O(nlogn)으로 가능하다.

vector<int> stateToVec(int state) {
    int mask = 0;
    vector<int> ret;
    for (int i = 8 - 1; i >= 0; i--) {
        int cand = (state / factorial[i]);
        for (int j = 0; j < 8; j++) {
            if (mask & (1 << j))
                continue;
            else if (cand)
                cand--;
            else {
                mask |= (1 << j);
                ret.push_back(j + 1);
                break;
            }
        }
        state %= factorial[i];
    }
    return ret;
} // O(n^2)

int dis[40321];
void bfs() {
    memset(dis, -1, sizeof(dis));
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        vector<int> cache = stateToVec(now);
        for (int i = 0; i < 8; i++) {
            for (int j = i + 1; j < 8; j++) {
                vector<int> cand = cache;
                for (int k = 0; k <= (j - i) / 2; k++) {
                    swap(cand[i + k], cand[j - k]);
                }
                int state_cand = vecToState(cand);
                if (dis[state_cand] == -1) {
                    q.push(state_cand);
                    dis[state_cand] = dis[now] + 1;
                }
            }
        }
    }
}

int main() {
    fastIO;
    initFactorial();
    bfs();
    int C;
    cin >> C;
    while (C--) {
        int n, list[8], sortedList[8];
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> list[i];
            sortedList[i] = list[i];
        }
        sort(sortedList, sortedList + n);
        map<int, int> compress;
        int idx = 1;
        for (int i = 0; i < n; i++) {
            compress[sortedList[i]] = idx++;
        }
        vector<int> num;
        for (int i = 0; i < n; i++) {
            num.push_back(compress[list[i]]);
        }

        cout << dis[vecToState(num)] << "\n";
    }
    return 0;
} // O(n^4)로는 안되나 보네..