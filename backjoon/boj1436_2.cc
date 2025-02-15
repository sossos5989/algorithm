#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int num, ans, cnt, k;
int main() {
    scanf("%d", &num);
    while (1) {
        if (cnt == num) break;
        if ((k % 1000) == 666) {
            for (int i = 0; i < 1000; i++) {
                if (cnt == num) break;
                ans = k * 1000 + i;
                cnt++;
            }
        } else if ((k % 100) == 66) {
            for (int i = 0; i < 100; i++) {
                if (cnt == num) break;
                ans = 600 + k * 1000 + i;
                cnt++;
            }
        } else if ((k % 10) == 6) {
            for (int i = 0; i < 10; i++) {
                if (cnt == num) break;
                ans = 660 + k * 1000 + i;
                cnt++;
            }
        } else {
            ans = 666 + k * 1000;
            cnt++;
        }
        k++;
    }
    printf("%d", ans);
}