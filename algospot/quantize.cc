#include <iostream>
#include <algorithm>
#include <cstring>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int N, M;
int list[100], pSum[101], pSqSum[101];

int cache[101][11];

void precalc() {
    sort(list, list + N);  // 정렬 수행
    pSum[0] = list[0];
    pSqSum[0] = list[0] * list[0];  // base case
    for (int i = 1; i < N; i++) {
        pSum[i] = pSum[i-1] + list[i];
        pSqSum[i] = pSqSum[i-1] + list[i] * list[i];
    }
}

int minerror(int start, int end) {
    int sum = pSum[end] - (start == 0 ? 0 : pSum[start - 1]);
    int sqsum = pSqSum[end] - (start == 0 ? 0 : pSqSum[start - 1]);
    int m = int(0.5 + (double)sum / (end - start + 1));
    return sqsum - 2 * m * sum + m * m * (end - start + 1);
}

int quantize(int f, int p) {

    if (f == N) return 0;
    if (p == 0) return 987654321;

    int& ret = cache[f][p];
    if (ret != -1) return ret;

    ret = 987654321;

    for (int i = 1; i + f <= N; i++) 
        ret = MIN(ret, minerror(f, f + i - 1) + quantize(f + i, p - 1));

    return ret;
}

int main() {
    int repeat;
    cin >> repeat;
    while (repeat > 0) {
        memset(cache, -1, sizeof(cache));
        cin >> N;
        cin >> M;
        for (int i = 0; i < N; i++) {cin >> list[i];}
        precalc();
        cout << quantize(0, M) << "\n";
        repeat--;
    }
    return 0;
}
