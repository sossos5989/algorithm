#include <cstring>
#include <iostream>
#include <regex>
#include <string>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const regex pattern("^(100+1+)$");

int n;
string input;

int dp[101];
bool isPattern(int k) {
    if (input.size() == k) return true; // base case
    if (input.size() < k) return false; // base case

    if (dp[k] != -1) return dp[k];

    bool ret = false;
    if (k + 1 < input.size() && input[k] == '0' && input[k + 1] == '1')
        ret = isPattern(k + 2);
    for (int i = 4; k + i <= input.size() && !ret; i++) {
        if (regex_match(input.substr(k, i), pattern)) ret = isPattern(k + i);
    }
    dp[k] = ret ? 1 : 0;
    return ret;
}

int main() {
    fastIO;
    cin >> n;
    while (n--) {
        cin >> input;
        memset(dp, -1, sizeof(dp));
        cout << (isPattern(0) ? "YES" : "NO") << endl;
    }
    return 0;
}

// 만약 다시 풀 수 있다면, 오토마타 이론을 이용해 다시 풀어볼 것.
// 그래프 이론: 오토마타의 상태 전이를 그래프 이론으로 표현 가능.
// DFA는 방향 그래프로 표현되며, 문자열을 O(n) 시간 복잡도로 판별.
// NFA → DFA 변환이 가능하며, 정규 표현식과 관계가 깊음.
// **그래프 탐색 알고리즘 (DFS, BFS)**은 오토마타와 밀접한 연관이 있음.