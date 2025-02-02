#include <iostream>
#include <string>
#include <cstring>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;


int N;
int list[100][100];
int cache[101][101];

int function(int a, int b) {
    int& ret = cache[a][b];
    if (ret != -1) return ret;
    if (a == N) return ret = 0;
    ret = list[a][b] + MAX(function(a+1, b), function(a+1, b+1));
    return ret;
}

int cache2[101][101];
int fun2(int a, int b) {
    if (a == N - 1) return 1;

    int& ret = cache2[a][b];
    if (ret != -1) return ret;

    ret = 0;
    if (cache[a+1][b] >= cache[a+1][b+1]) ret += fun2(a+1, b);
    if (cache[a+1][b] <= cache[a+1][b+1]) ret += fun2(a+1, b+1);

    return ret;
}  // 오.. 구현한거 예제랑 완전 똑같이함 기분 개좋음 ㅋㅋㅋ

int main() {
    int repeat;
    cin >> repeat;
    for(; repeat > 0; repeat--) {
        cin >> N;
        memset(cache, -1, sizeof(cache));
        memset(cache2, -1, sizeof(cache2));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)  // j < i 가 핵심
            {
                cin >> list[i][j];
            }
        }  // 입력
        function(0, 0);
        cout << fun2(0, 0) << "\n";
    }
    return 0;
}