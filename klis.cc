#include <vector>
#include <iostream>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        vector<int> DP(n + 1, 1);
        int maxLen = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (arr[j] < arr[i] && DP[j] + 1 > DP[i]) {
                    DP[i] = DP[j] + 1;
                }
            }
            maxLen = max(maxLen, DP[i]);
        }

        vector<vector<int>> nxt(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= i + 1; j--) {
                if (arr[j] > arr[i] && DP[j] == DP[i] + 1) {
                    nxt[i].push_back(j);
                }
            }
        }

        vector<long long> cacheCnt(n+1, -1);
        function<long long(int)> paths_count = [&](int cur) -> long long {
            if (cacheCnt[cur] != -1) {
                return cacheCnt[cur];
            }
            // 마지막 노드(DP[cur] == maxLen)면 경로 1개
            if (DP[cur] == maxLen) {
                cacheCnt[cur] = 1;
                return 1;
            }
            long long sumCnt = 0;
            for (int nx : nxt[cur]) {
                long long tmp = paths_count(nx);
                // 누적 과정에서 k를 넘어가면 k+1로 “고정”
                if (sumCnt + tmp >= k + 1) {
                    sumCnt = k + 1; 
                    break;
                } else {
                    sumCnt += tmp;
                }
            }
            cacheCnt[cur] = sumCnt;
            return sumCnt;
        };

        vector<int> source;
        for (int i = n; i >= 1; i--) {
            if (DP[i] == 1) {
                source.push_back(i);
            }
        }

        long long totalPaths = 0;
        for (int s : source) {
            long long cnt = paths_count(s);
            if (totalPaths + cnt >= k + 1) {
                totalPaths = k + 1;
                break;
            }
            totalPaths += cnt;
        }


        // nmaxLen 출력
        cout << maxLen << "\n";

        // (1) source 중에서 k에 해당하는 시작 노드 찾기
        int start = -1;
        for (int s : source) {
            long long cnt = cacheCnt[s];
            if (cnt >= k) {
                start = s;
                break;
            } else {
                k -= cnt;  // k번째 경로가 아니므로 k에서 빼주기
            }
        }

        // (2) start부터 자식 노드 nxt[cur]를 순회하며 k번째 경로 구성
        vector<long long> lisPath;
        int cur = start;
        while (true) {
            lisPath.push_back(arr[cur]);
            // 이미 마지막 노드(길이가 maxLen)라면 종료
            if (DP[cur] == maxLen) {
                break;
            }
            for (int nx : nxt[cur]) {
                long long cnt = cacheCnt[nx];
                if (cnt >= k) {
                    cur = nx;
                    break;
                } else {
                    k -= cnt;
                }
            }
        }

        // 결과 출력
        for (auto &val : lisPath) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}