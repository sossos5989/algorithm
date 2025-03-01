#include <stdio.h>
int n, s, f = 1;
char c;
int main(void) {
    while (c != '\n') {
        scanf("%d%c", &n, &c);
        s += n * f;
        if (c == '-') f = -1;
    }
    printf("%d", s);
}