#include <stdio.h>
int main() {
    int n, m, s;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        for (m = n, s = 0; m > 0; m /= 10) {
            s = s * 10;
            s += m % 10;
        }
        printf(s == n ? "yes\n" : "no\n");
    }
}