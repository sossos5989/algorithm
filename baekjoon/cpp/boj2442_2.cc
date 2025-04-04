#include <stdio.h>
int i = 1, n, h;
int main() {
    for (scanf("%d", &n); i < n * 2; ++i)
        putchar(i - h > n ? 10 + h++ * (i = 0) : i + h < n ? 32 : 42);
}