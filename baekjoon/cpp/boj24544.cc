#include <cstdio>

int main() {
    int n, list[1001], isQueue, s1 = 0, s2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", list + i);
    for (int i = 0; i < n; i++) {
        scanf("%d", &isQueue);
        s1 += list[i];
        s2 += list[i] * !isQueue;
    }
    printf("%d\n%d", s1, s2);
    return 0;
}