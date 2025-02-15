#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        // 각 문서를 (중요도, 인덱스) 형태로 큐에 저장
        queue<pair<int, int>> q;
        // 최대 힙 (priority_queue는 기본적으로 최대 힙)
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            int importance;
            cin >> importance;
            q.push({importance, i});
            pq.push(importance);
        }

        int printOrder = 0;
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            // 현재 문서의 중요도가 가장 큰 중요도와 같다면 인쇄
            if (current.first == pq.top()) {
                printOrder++;
                pq.pop();
                // 우리가 원하는 문서라면 출력 후 break
                if (current.second == m) {
                    cout << printOrder << "\n";
                    break;
                }
            } else {
                // 중요도가 가장 크지 않다면 큐의 뒤로 재배치
                q.push(current);
            }
        }
    }
    return 0;
} // priority_queue와 queue를 이용한 AI코드이다.