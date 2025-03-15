#include <cstdio>
using namespace std;

int C, H, W, N;

int main() {
    scanf("%d", &C);
    while (C--) {
        scanf("%d %d %d", &H, &W, &N);
        printf("%d%02d\n", (N - 1) % H + 1, (N + H - 1) / H);
    }
    return 0;
}