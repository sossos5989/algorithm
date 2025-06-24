#include <cstdio>
#include <math.h>
using namespace std;

int main() {
    int n, v, list[51];
    scanf("%d %d", &n, &v);

    for (int i = 1; i <= n; i++)
        scanf("%d", &list[i]);

    int ans = n;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (abs(list[j] - list[i]) >= v)
                ans = min(ans, i / 2 + (abs(i - j) + 3) / 2);

    printf("%d", ans);
    return 0;
}