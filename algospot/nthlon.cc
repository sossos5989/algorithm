#include <iostream>
#include <queue>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        int m, a, b;
        // first = gap, second = minute;
        vector<pair<int, int>> plus;
        vector<pair<int, int>> minus;

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (a - b > 0) {
                plus.push_back(make_pair(a - b, a));
            } else {
                minus.push_back(make_pair(b - a, a));
            }
        }

        int minute[50000];
        for (int i = 0; i < 50000; i++) {
            minute[i] = 1e9;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        q.push(make_pair(0, 0));
        minute[0] = 0;
        while (!q.empty()) {
            pair<int, int> here = q.top();
            q.pop();
            if (minute[here.first] < here.second) continue;
            for (auto &i : plus) {
                int new_gap = here.first + i.first;
                int new_min = here.second + i.second;
                if (minute[new_gap] > new_min && new_gap < 50000) {
                    q.push(make_pair(new_gap, new_min));
                    minute[new_gap] = new_min;
                }
            }
        }

        int test[50000];
        for (int i = 0; i < 50000; i++) {
            test[i] = 1e9;
        }

        q.push(make_pair(0, 0));
        test[0] = 0;
        while (!q.empty()) {
            pair<int, int> here = q.top();
            q.pop();
            if (test[here.first] < here.second) continue;
            for (auto &i : minus) {
                int new_gap = here.first + i.first;
                int new_min = here.second + i.second;
                if (test[new_gap] > new_min && new_gap < 50000) {
                    q.push(make_pair(new_gap, new_min));
                    test[new_gap] = new_min;
                }
            }
        }
        if (plus.empty() || minus.empty()) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        int min = 2 * 1e9;
        for (int i = 1; i < 50000; i++) {
            int cand = test[i] + minute[i];
            if (min > cand) min = cand;
        }
        cout << min << "\n";
    }
    return 0;
}
