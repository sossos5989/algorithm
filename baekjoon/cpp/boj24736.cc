#include <cstdio>
using namespace std;

int main() {
    int t, f, s, p, c;
    for (; ~scanf("%d %d %d %d %d", &t, &f, &s, &p, &c);)
        printf("%d\n", 6 * t + 3 * f + 2 * s + 1 * p + 2 * c);
    return 0;
}