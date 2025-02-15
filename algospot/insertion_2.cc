#include <stdio.h>

int N, input[50000], A[50000], tree[200000];

int init(int node, int st, int ed) {
    if (st == ed) return tree[node] = 1;
    return tree[node] = init(node * 2, st, (st + ed) / 2) +
                        init(node * 2 + 1, (st + ed) / 2 + 1, ed);
}

int find_kth(int node, int st, int ed, int k) {
    tree[node] -= 1;

    if (st == ed) return st;

    if (tree[node * 2] >= k)
        return find_kth(node * 2, st, (st + ed) / 2, k);
    else
        return find_kth(node * 2 + 1, (st + ed) / 2 + 1, ed,
                        k - tree[node * 2]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        init(1, 1, N);

        for (int i = 0; i < N; i++)
            scanf("%d", &input[i]);

        for (int i = N - 1; i >= 0; i--) {
            A[i] = find_kth(1, 1, N, i + 1 - input[i]);
        }

        for (int i = 0; i < N; i++)
            printf("%d ", A[i]);
        printf("\n");
    }
    return 0;
}