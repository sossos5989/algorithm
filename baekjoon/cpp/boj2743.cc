#import <ios>
int a;
main() {
    while (getchar() - '\n')
        a++;
    printf("%d", a);
}