#include <cstdio>

int main() {
    int c = 0;
    char input[1000011];
    input[fread(input, 1, 1000011, stdin)] = 0;
    for (int i = 0; input[i]; ++i) {
        if (input[i] > 33 && input[i + 1] < 33) c++;
    }
    printf("%d", c);
}
// 인상적인 코드, 뒤에 0을 넣음으로써 뒷 공백도 처리가 가능한 알고리즘이 됨.