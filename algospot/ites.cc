#include <iostream>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int k, n;

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> k >> n;
        queue<int> q;
        int sum = 0, ret = 0;
        unsigned int now = 1983;
        while (n--) {
            int cand = now % 10000 + 1;
            q.push(cand);
            sum += cand;
            while (sum > k) {
                sum -= q.front();
                q.pop();
            }
            if (sum == k) ret++;
            now = now * 214013u + 2531011u;
        }
        cout << ret << endl;
    }
    return 0;
}

// 부분합 sum n 50000000 O(n)이 되나..?