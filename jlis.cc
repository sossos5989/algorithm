#include <iostream>
#include <cstring>
#include <limits>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int N, M;
int list1[100];
int list2[100];
int cache[101][101];

int jlis(int idx_a, int idx_b) {
    int& ret = cache[idx_a+1][idx_b+1];
    if (ret != -1) return ret;

    ret = 0;  // 값의 최소는 2

    long long a = (idx_a == -1 ? NEGINF : list1[idx_a]);
    long long b = (idx_b == -1 ? NEGINF : list2[idx_b]);
    long long maxEle = MAX(a, b);

    for (int next = idx_a + 1; next < N; next++)
    {
        if(maxEle < list1[next]) ret = MAX(ret, 1 + jlis(next,idx_b));
    }
    for (int next = idx_b + 1; next < M; next++)
    {
        if(maxEle < list2[next]) ret = MAX(ret, 1 + jlis(idx_a,next));
    }
    // 반복문 2개로 가능
    return ret;
}

int main() {
    int repeat;
    cin >> repeat;
    while (repeat > 0)
    {
        memset(cache, -1, sizeof(cache));
        cin >> N;
        cin >> M;
        for (int i = 0; i < N; i++) {cin >> list1[i];}
        for (int i = 0; i < M; i++) {cin >> list2[i];}
        cout << jlis(-1,-1) << "\n";
        repeat--;
    }
    return 0;
}