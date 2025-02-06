#import <ios>
int c;
main() {
    for (; c = ~getchar(); putchar(~c))
        ;
} // simple code