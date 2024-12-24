#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int path_size[501];
int calculatePath(int index, vector<vector<int>>& next) {
    int& ret = path_size[index];
    if (ret != -1) return ret;

    if (!next[index].size()) return ret = 1;  // base case
    ret = 0;
    for (int element : next[index]) {
        ret += calculatePath(element, next);
    }
    return ret;
}

// 구현을 못하겠어서 gpt형님 사용..
void findKthLIS(int index, int& k, vector<vector<int>>& next_element, vector<int>& result) {
    result.push_back(index);

    if (next_element[index].empty()) return;  // 더 이상 다음 노드가 없으면 종료

    for (int element : next_element[index]) {
        if (path_size[element] < k) {
            k -= path_size[element];  // 해당 경로를 건너뜀
        } else {
            findKthLIS(element, k, next_element, result);  // k번째 경로를 탐색
            break;
        }
    }
}

int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat--) {
        int n, k; 
        cin >> n >> k;

        vector<int> list(n + 1);
        for (int i = 1; i <= n; i++) cin >> list[i];  // list[1...n]

        // list[1...i]까지의 최대 LIS 길이를 계산해 DP table에 저장합니다.
        vector<int> DP(n + 1); DP[1] = 1;
        for (int i = 2; i <= n; i++) {
            DP[i] = 1;
            for (int j = 1; j < i; j++) {
                if (list[i] > list[j] && DP[i] <= DP[j] + 1) {
                    if (DP[i] < DP[j] + 1) {
                        DP[i] = DP[j] + 1;
                    }
                }
            }
        }  // O(n^2)
        
        // 각 element의 다음 element를 가리키는 edge를 next_element에 저장합니다.
        // 이후 graph의 source에 해당하는 element들을 source에 저장합니다.
        vector<vector<int>> next_element(n + 1);
        vector<int> source;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (list[j] > list[i] && DP[j] == DP[i] + 1) {
                    next_element[i].push_back(j);
                }
            }
            if (next_element[i].size() && DP[i] == 1) source.push_back(i);
        }  // next_elements, source O(n^2)

        // 이후 next_element를 이용하여 element에서 sink까지의 경우의 수를 저장하는 path_size를 저장합니다.
        memset(path_size, -1, sizeof(path_size));
        for (int r : source) {
            calculatePath(r, next_element);
        }

        // k번째 LIS를 탐색
        vector<int> result;
        for (int r : source) {
            if (path_size[r] < k) {
                k -= path_size[r];  // source 노드에서 해당 경로를 건너뜀
            } else {
                findKthLIS(r, k, next_element, result);  // k번째 LIS 경로 탐색
                break;
            }
        }

        // k번째 LIS 출력
        cout << "k-th LIS: ";
        for (int idx : result) {
            cout << list[idx] << " ";
        }
        cout << "\n";
        
    }
    return 0;
}
