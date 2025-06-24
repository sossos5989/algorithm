n, q[3000][3000], c[4], a, i, j;
g(int x, int y, int k) {
    a = q[x][y];
    for (i = x; i < x + k; i++) {
        for (j = y; j < y + k; j++) {
            if (a != q[i][j]) {
                k /= 3;
                g(x, y, k);
                g(x + k, y, k);
                g(x + k * 2, y, k);
                g(x, y + k, k);
                g(x + k, y + k, k);
                g(x + k * 2, y + k, k);
                g(x, y + k * 2, k);
                g(x + k, y + k * 2, k);
                g(x + k * 2, y + k * 2, k);
                return 0;
            }
        }
    }
    c[a + 1]++;
}
main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &q[i][j]);
    g(1, 1, n);
    for (i = 0; i < 3; i++)
        printf("%d\n", c[i]);
}