#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int prevv[10000];
char choose[10000];

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        memset(prevv, -1, sizeof(prevv));
        int a, b;
        cin >> a >> b;
        queue<int> q;
        q.push(a);
        prevv[a] = -2;
        choose[a] = 'A';
        while (!q.empty()) {
            int head = q.front();
            if (head == b) break;
            q.pop();
            int times2 = (head * 2) % 10000;
            int minus1 = (head + 9999) % 10000;
            int d1 = (head / 1000) % 10, d2 = (head / 100) % 10,
                d3 = (head / 10) % 10, d4 = head % 10;

            int rotateL = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
            int rotateR = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
            if (prevv[times2] == -1) {
                q.push(times2);
                prevv[times2] = head;
                choose[times2] = 'D';
            }
            if (prevv[minus1] == -1) {
                q.push(minus1);
                prevv[minus1] = head;
                choose[minus1] = 'S';
            }
            if (prevv[rotateL] == -1) {
                q.push(rotateL);
                prevv[rotateL] = head;
                choose[rotateL] = 'L';
            }
            if (prevv[rotateR] == -1) {
                q.push(rotateR);
                prevv[rotateR] = head;
                choose[rotateR] = 'R';
            }
        }
        int ptr = prevv[b];
        string ans;
        ans += choose[b];
        while (prevv[ptr] != -2) {
            ans += choose[ptr];
            ptr = prevv[ptr];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}