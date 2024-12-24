#include <iostream>
#include <cstring>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int N;
int cache[501];
int list[500];
int lis1(int a) {
    int& ret = cache[a+1];
    if(ret != -1) return ret;
    ret = 0;
    for (int i = a + 1; i < N; i++)
    {
        if(a == -1 || list[a] < list[i]) ret = MAX(ret, lis1(i) + 1);
    }
    return ret;
}
// 아까 내가 작성한 코드의 문제점
// 시작점에 대해 배제가 되었음. lis1를 각 인덱스별로 실행시켜야함. 그중 MAX를 뽑는 것
// + 1 자체가 기본값 1을 의미하므로, ret = 1 이 아닌 ret = 0이 맞음

int main() {
    int repeat;
    cin >> repeat;

    for(; repeat > 0; repeat--) {
        memset(cache, -1, sizeof(cache));
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> list[i];
        }
        cout << lis1(-1) << "\n";
    }
    return 0;
}
