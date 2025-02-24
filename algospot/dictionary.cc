#include <algorithm>
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
        int n;
        string prev, now;
        vector<vector<int>> alphabet(26); // 그래프
        int inDegree[26] = {0};

        cin >> n >> prev;
        while (--n) {
            cin >> now;
            int i = 0, size = min(prev.size(), now.size());
            while (i < size) {
                if (prev[i] != now[i]) {
                    vector<int> &cache = alphabet[prev[i] - 'a'];
                    int value = now[i] - 'a';
                    if (find(cache.begin(), cache.end(), value) ==
                        cache.end()) {
                        cache.push_back(value);
                        inDegree[value]++;
                    }
                    break;
                }
                i++;
            }
            prev = now;
        }

        // Kahn's algorithm
        string answer;
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (!inDegree[i]) q.push(i);
        }
        int popcount = 0;
        while (!q.empty()) {
            answer += (char)(q.front() + 'a');
            for (int &i : alphabet[q.front()]) {
                inDegree[i]--;
                if (!inDegree[i]) q.push(i);
            }
            q.pop();
            popcount++;
        }

        if (popcount != 26) answer = "INVALID HYPOTHESIS";

        cout << answer << "\n";
    }
    return 0;
}