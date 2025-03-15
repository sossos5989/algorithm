#include <cstdio>

int n, in[100000], rev_post[100000];

void pre(int l, int r, int k) {
    for (int i = l; i < r; ++i) {
        if (rev_post[k] == in[i]) {
            printf("%d ", rev_post[k]);
            pre(l, i, k + r - i);
            pre(i + 1, r, k + 1);
            return;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", in + i);
    for (int i = n - 1; i >= 0; i--)
        scanf("%d", rev_post + i);
    pre(0, n, 0);
}