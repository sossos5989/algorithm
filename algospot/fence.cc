#include <iostream>
#include <stack>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, h[20001];

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        h[n] = 0;
        stack<int> left; // 오름차순으로 값이 들어감
        int ret = 0;
        for (int i = 0; i <= n; i++) {
            while (!left.empty() && h[left.top()] > h[i]) {
                int j = left.top();
                left.pop();
                int width = i;
                if (!left.empty()) width -= left.top() + 1;
                ret = max(ret, h[j] * width);
            }
            left.push(i);
        }
        cout << ret << endl;
    }
    return 0;
}

// width는 0부터 i - 1까지 너비, block이 계속 오름차순이였다면
// 최대 블록 높이가 왼쪽 블록임을 알 수 있음 이를 이용해 넓이를 구한다.