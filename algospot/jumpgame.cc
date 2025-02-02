#include <iostream>
#include <cstring>

using namespace std;

int N;
int cache[100][100];
int input[100][100];

int jumpgame(int x, int y) {
    if (x >= N || y >= N) return 0;  // base case, ret이 아닌 진짜 숫자 값 넣기
    if (x == N - 1 && y == N - 1) return 1;  

    int& ret = cache[x][y];
    int& jump = input[x][y];

    if(ret != -1) return ret;  // memorization
    ret = jumpgame(x + jump, y) | jumpgame(x, y + jump);  // recursive case |와 ||다 됨.

    return ret;
}

int main() {
    int repeat;
    cin >> repeat;
    for ( ; repeat > 0; repeat-- )  // 테스트 케이스
    {
        memset(cache, -1, sizeof(cache));  // available의 모든 원소 -1 초기화
        cin >> N;

        for (int i = 0 ; i < N; i++) {
            for (int j = 0; j < N; j++)
            {
                cin >> input[i][j];
            }
        }

        string answer = "NO";
        if (jumpgame(0, 0) == 1) answer = "YES";
        cout << answer << endl;
    }
    return 0;
}