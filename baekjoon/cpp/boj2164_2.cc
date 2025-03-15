#include <stdio.h>
int main() {
    int N, i = 1;
    scanf("%d", &N);
    while (i < N)
        i *= 2;
    printf("%d", 2 * N - i);
    return 0;
} // 점화식을 세울 수 있음