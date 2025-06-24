main(n, m) {
    scanf("%d%d", &n, &m);
    n -= 1023;
    puts(n > 0 ? n & m ^ n ? "Impossible" : "Thanks" : "No thanks");
}