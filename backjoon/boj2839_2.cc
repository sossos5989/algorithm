#include <stdio.h>
int main(void) {
    int n, i;
    scanf("%d", &n);
    for (i = n / 5; i >= 0 && (n - 5 * i) % 3;)
        i--;
    printf("%d", i < 0 ? -1 : (i + (n - 5 * i) / 3));
}