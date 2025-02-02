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

int main() {
    int repeat;
    cin >> repeat;
    for(; repeat > 0; repeat--) {
        cin >> N;
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)  // j < i 가 핵심
            {
                cin >> list[i][j];
            }
        }  // 입력
        cout << function(0, 0) << "\n";
    }
    return 0;
}