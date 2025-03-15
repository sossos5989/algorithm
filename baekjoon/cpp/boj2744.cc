#include <cstdio>
char c;
int main() {
    while (~scanf(" %c", &c))
        printf("%c", c ^ 32);
    return 0;
} // 소문자와 대문자의 간격이 정확히 32이다!